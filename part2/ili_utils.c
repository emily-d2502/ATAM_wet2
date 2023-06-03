#include <asm/desc.h>

void my_store_idt(struct desc_ptr *idtr) {
    asm(
        "SIDT %0;"
        : "=m"(idtr)
        : 
        :
    );
}

void my_load_idt(struct desc_ptr *idtr) {
    asm(
        "LIDT %0;"
        : 
        : "m"(idtr)
        : 
    );
}

void my_set_gate_offset(gate_desc *gate, unsigned long addr) {
    gate->offset_low = addr & 0xFFFF;

    addr = addr >> 16;
    gate->offset_middle = addr & 0xFFFF;

    addr = addr >> 16;
    gate->offset_high = addr;
}

unsigned long my_get_gate_offset(gate_desc *gate) {
    unsigned long ret = gate->offset_high;

    ret = ret << 16;
    ret += gate->offset_middle;

    ret = ret << 16;
    ret += gate->offset_low;
    return ret;
}
