`timescale 1ns / 1ps

module subtractor #(parameter SIZE = 2)
(
    input [SIZE-1:0] a, b,
    output [SIZE-1:0] diff,
    output borrow
);

    wire [SIZE:0] a_padded,b_padded,diff_with_borrow;

    assign a_padded = {1'b0,a};
    assign b_padded = {1'b0,b};

    assign diff_with_borrow = a_padded - b_padded;

    assign diff = diff_with_borrow[SIZE-1:0];
    assign borrow = diff_with_borrow[SIZE];

endmodule
