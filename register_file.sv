module register_file
(
	input wire clk,
	input wire reset,
	input wire [63:0] stackptr,
	
	input wire [4:0] reg1,
	input wire [4:0] reg2,
	output wire [63:0] val1,
	output wire [63:0] val2,

	input wire write_enable,
	input wire [63:0] write_value,
	input wire [4:0] write_register,
	output wire write_ready,
	input wire ecall,
	output wire ecall_done,

	input wire is_store,
    input wire [63:0] store_addr,
    input wire [63:0] store_data,
    input wire [1:0] store_size
);

	parameter ECALL_IDLE = 2'd0,
          	ECALL_IN_PROGRESS = 2'd1,
			ECALL_DONE = 2'd2;

	logic [63:0] registers [31:0];
	logic [2:0] ecall_state, next_ecall_state;
	logic pending_write; 
	logic pending_and_ecall;
	assign pending_and_ecall = pending_write && next_ecall_state == ECALL_IN_PROGRESS;
	logic wr_ecall;
	assign wr_ecall = write_enable && next_ecall_state == ECALL_IN_PROGRESS;
	always_ff @(posedge clk) begin
		if(reset) begin
			ecall_state <= ECALL_IDLE;
		end else begin
			if (is_store) begin
				do_pending_write(store_addr, store_data, 2**(store_size));
				pending_write <= 1;
			end else begin
				pending_write <= 0; 
			end
			if(next_ecall_state == ECALL_IN_PROGRESS) begin
				// $display("DOING ECALLL!!!!");
				do_ecall(registers[17], registers[10], registers[11], registers[12], registers[13], registers[14], registers[15], registers[16], registers[10]);
				ecall_state <= ECALL_DONE;
			end else begin
				ecall_state <= next_ecall_state;
			end
		end
	end

	always_ff @(posedge clk) begin
		if(reset) begin
			integer i;
			for (i = 0; i < 32; i = i + 1) begin
				registers[i] <= 64'b0;
			end
			registers[2] <= stackptr;
			/* TEMP CHANGES */
			// registers[8] <= 63'h1000;
			// registers[9] <= 63'h2000;
			// registers[10] <= 63'h3000;
			// registers[11] <= 63'hAAAAAAAAAAAA;
			// registers[12] <= 63'hBBBBBBBBBBBB;
			// registers[13] <= 63'hCCCCCCCCCCCC;
		end else begin
			if(write_enable) begin
				registers[write_register] <= write_register == 0 ? 0 : write_value;	
			end
		end
	end

	always_comb begin
		write_ready = 1;
		val1 = write_enable && write_register == reg1 ? write_value : registers[reg1];
		val2 = write_enable && write_register == reg2 ? write_value : registers[reg2];
	end

	always_comb begin
		ecall_done = ecall_state == ECALL_DONE;
		if(ecall) begin
			next_ecall_state = ecall_state == ECALL_DONE ? ECALL_DONE : ECALL_IN_PROGRESS;
		end else begin
			next_ecall_state = ECALL_IDLE;
		end
	end

endmodule