`timescale 1ns / 1ps

module control_unit(
    input clk,
    
    output [3:0] machine_code // this defines the output is 4-bit and output is called machine_code
                              // 3, 2, 1 are op code and 0 is operand/OpSel
    );

wire [2:0] count;
wire equal, not_equal;

    mux8_4bit_wide mux8_4bit(
    .in0(4'b0010), // CLR
    .in1(4'b0001), // LOAD
    .in2(4'b1111), // MUL
    .in3(4'b1011), // SUB
    .in4(4'b1011), // SUB
    .in5(4'b0000), // NOP // changed from 4'b1000 because 1000 is Logical Shift Left, not NOP
    .in6(4'b0000), // NOP // changed from 4'b1000
    .in7(4'b0000), // NOP // changed from 4'b1000
    .sel(count),
    .out(machine_code)
    );
    
    UpCounter counter(
    .clk(clk),
    .en(not_equal),
    .reset(), // removed 1'b0
    .cur_count(count)
    );
    
    EqualityComp EqualityComp(
    .a(3'b101),
    .b(count),
    .equal(equal),
    .less_than(),
    .greater_than()
    );
    
    not NOT(not_equal, equal); // not_equal is after the not gate, equal is beforez * previously not NOT(not_equal, equal)
    
endmodule
