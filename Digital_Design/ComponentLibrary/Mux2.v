
module mux2 #(parameter SIZE=2)
(   
	input sel,
	input  [SIZE-1:0] in0,in1,
    output reg [SIZE-1:0] out
);

    always@(*)
        case(sel)
            1'b0: out = in0;
            1'b1: out = in1;
            default: out = {SIZE{1'bx}};
        endcase
endmodule
