// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+1,(vlTOPp->top__DOT__pc),64);
	vcdp->chgBus  (c+3,(vlTOPp->top__DOT__if_id_ctr),8);
	vcdp->chgBus  (c+4,(vlTOPp->top__DOT__id_ex_ctr),8);
	vcdp->chgBus  (c+5,(vlTOPp->top__DOT__ex_mem_ctr),8);
	vcdp->chgBus  (c+6,(vlTOPp->top__DOT__mem_wb_ctr),8);
	vcdp->chgBus  (c+7,((0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__if_id_ctr)))),8);
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+8,(vlTOPp->clk));
	vcdp->chgBit  (c+9,(vlTOPp->reset));
	vcdp->chgBit  (c+10,(vlTOPp->hz32768timer));
	vcdp->chgQuad (c+11,(vlTOPp->entry),64);
	vcdp->chgQuad (c+13,(vlTOPp->stackptr),64);
	vcdp->chgQuad (c+15,(vlTOPp->satp),64);
	vcdp->chgBus  (c+17,(vlTOPp->m_axi_awid),13);
	vcdp->chgQuad (c+18,(vlTOPp->m_axi_awaddr),64);
	vcdp->chgBus  (c+20,(vlTOPp->m_axi_awlen),8);
	vcdp->chgBus  (c+21,(vlTOPp->m_axi_awsize),3);
	vcdp->chgBus  (c+22,(vlTOPp->m_axi_awburst),2);
	vcdp->chgBit  (c+23,(vlTOPp->m_axi_awlock));
	vcdp->chgBus  (c+24,(vlTOPp->m_axi_awcache),4);
	vcdp->chgBus  (c+25,(vlTOPp->m_axi_awprot),3);
	vcdp->chgBit  (c+26,(vlTOPp->m_axi_awvalid));
	vcdp->chgBit  (c+27,(vlTOPp->m_axi_awready));
	vcdp->chgQuad (c+28,(vlTOPp->m_axi_wdata),64);
	vcdp->chgBus  (c+30,(vlTOPp->m_axi_wstrb),8);
	vcdp->chgBit  (c+31,(vlTOPp->m_axi_wlast));
	vcdp->chgBit  (c+32,(vlTOPp->m_axi_wvalid));
	vcdp->chgBit  (c+33,(vlTOPp->m_axi_wready));
	vcdp->chgBus  (c+34,(vlTOPp->m_axi_bid),13);
	vcdp->chgBus  (c+35,(vlTOPp->m_axi_bresp),2);
	vcdp->chgBit  (c+36,(vlTOPp->m_axi_bvalid));
	vcdp->chgBit  (c+37,(vlTOPp->m_axi_bready));
	vcdp->chgBus  (c+38,(vlTOPp->m_axi_arid),13);
	vcdp->chgQuad (c+39,(vlTOPp->m_axi_araddr),64);
	vcdp->chgBus  (c+41,(vlTOPp->m_axi_arlen),8);
	vcdp->chgBus  (c+42,(vlTOPp->m_axi_arsize),3);
	vcdp->chgBus  (c+43,(vlTOPp->m_axi_arburst),2);
	vcdp->chgBit  (c+44,(vlTOPp->m_axi_arlock));
	vcdp->chgBus  (c+45,(vlTOPp->m_axi_arcache),4);
	vcdp->chgBus  (c+46,(vlTOPp->m_axi_arprot),3);
	vcdp->chgBit  (c+47,(vlTOPp->m_axi_arvalid));
	vcdp->chgBit  (c+48,(vlTOPp->m_axi_arready));
	vcdp->chgBus  (c+49,(vlTOPp->m_axi_rid),13);
	vcdp->chgQuad (c+50,(vlTOPp->m_axi_rdata),64);
	vcdp->chgBus  (c+52,(vlTOPp->m_axi_rresp),2);
	vcdp->chgBit  (c+53,(vlTOPp->m_axi_rlast));
	vcdp->chgBit  (c+54,(vlTOPp->m_axi_rvalid));
	vcdp->chgBit  (c+55,(vlTOPp->m_axi_rready));
	vcdp->chgBit  (c+56,(vlTOPp->m_axi_acvalid));
	vcdp->chgBit  (c+57,(vlTOPp->m_axi_acready));
	vcdp->chgQuad (c+58,(vlTOPp->m_axi_acaddr),64);
	vcdp->chgBus  (c+60,(vlTOPp->m_axi_acsnoop),4);
    }
}
