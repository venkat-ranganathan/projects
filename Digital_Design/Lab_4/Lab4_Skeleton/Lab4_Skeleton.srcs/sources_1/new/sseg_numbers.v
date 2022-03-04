`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/25/2019 02:17:44 PM
// Design Name: 
// Module Name: sseg_numbers
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module sseg_numbers(
    input [3:0] seg_control,

    output [6:0] segment 
    );
    //-----------------Segment A-------------------
    reg [15:0] A;
    always @ (A)
    begin
        A <= 16'b0010100000010010;
    end
    assign segment[0] = A[seg_control];
    //-----------------Segment B-------------------
    reg [15:0] B; 
    always @ (B)
    begin
        B <= 16'b1101100001100000;
    end
    assign segment[1] = B[seg_control];
    //-----------------Segment C-------------------
    reg [15:0] C; 
    always @ (C)
    begin
        C <= 16'b1101000000000100;
    end
    assign segment[2] = C[seg_control];
    //-----------------Segment D-------------------
    reg [15:0] D; 
    always @ (D)
    begin
        D <= 16'b1000010010010010;
    end
    assign segment[3] = D[seg_control];
    //-----------------Segment E-------------------
    reg [15:0] E; 
    always @ (E)
    begin
        E <= 16'b0000001010111010;
    end
    assign segment[4] = E[seg_control];
    //-----------------Segment F-------------------
    reg [15:0] F; 
    always @ (F)
    begin
        F <= 16'b0010000010001110;
    end
    assign segment[5] = F[seg_control];
    //-----------------Segment G-------------------
    reg [15:0] G; 
    always @ (G)
    begin
        G <= 16'b0001000010000011;
    end
    assign segment[6] = G[seg_control];
endmodule
