module mux4 #(  parameter SIZE = 1)

(   input  [SIZE-1:0] in3,in2,in1,in0,
    input [1:0] sel,
    output reg [SIZE-1:0] out
);

    always@(*)
        case(sel)
            2'b00: out=in0;
            2'b01: out=in1;
            2'b10: out=in2;
            2'b11: out=in3;
            default: out={SIZE{1'bx}};
        endcase
endmodule