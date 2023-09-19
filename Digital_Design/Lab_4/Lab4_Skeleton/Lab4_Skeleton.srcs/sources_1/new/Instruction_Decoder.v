`timescale 1ns / 1ps

module Instruction_Decoder(
    input [3:0] opcode,
    output capture_C, capture_Z, capture_N
    );
    
    // Declare CZN output wire and assign bit width
    wire [2:0] czn_wire;
    
    // 16-bit mux, assign codes to 16 inputs, plus opcode (sel) and output (czn wire)
    // need to specify bit width of mux
    mux16 #(3) mux16(
    .in0(3'b000),
    .in1(3'b011),
    .in2(3'b011),
    .in3(3'b011),
    .in4(3'b111),
    .in5(3'b111),
    .in6(3'b111),
    .in7(3'b111),
    .in8(3'b000),
    .in9(3'b000),
    .in10(3'b000),
    .in11(3'b000),
    .in12(3'b000),
    .in13(3'b000),
    .in14(3'b000),
    .in15(3'b000),
    .sel(opcode),
    .out(czn_wire)
    );
    
    // Assign each bit to capture_C, capture_Z, and capture_N, respectively
    assign czn_wire[2] = capture_C;
    assign czn_wire[1] = capture_Z;
    assign czn_wire[0] = capture_N;

endmodule
