`timescale 1ns / 1ps

module Instruction_ROM(
    input [3:0] Current_Instruction_address,
    output [8:0] Instruction
    );
    
    reg [8:0] Instruction_reg;
    assign Instruction = Instruction_reg;
    
    always @ (*)
    begin
     case (Current_Instruction_address)
            0:  Instruction_reg <= (9'h100);
            1:  Instruction_reg <= (9'h05A);
            2:  Instruction_reg <= (9'h030);
            3:  Instruction_reg <= (9'h0CF);
            4:  Instruction_reg <= (9'h101);
            5:  Instruction_reg <= (9'h035);
            6:  Instruction_reg <= (9'h0DA);
            7:  Instruction_reg <= (9'h05A);
            8:  Instruction_reg <= (9'h059);
            9:  Instruction_reg <= (9'h00E);
            10: Instruction_reg <= (9'h058);
            11: Instruction_reg <= (9'h0DD);
            12: Instruction_reg <= (9'h103);
            13: Instruction_reg <= (9'h000);
            14: Instruction_reg <= (9'h082);
            default: Instruction_reg <= (9'h08F);
        endcase
        
        // The below values Set, then clears C, Z, N in order
       /* case (Current_Instruction_address)
            0:  Instruction_reg <= (9'h100);
            1:  Instruction_reg <= (9'h054);
            2:  Instruction_reg <= (9'h055);
            3:  Instruction_reg <= (9'h05A);
            4:  Instruction_reg <= (9'h044);
            5:  Instruction_reg <= (9'h10C);
            6:  Instruction_reg <= (9'h05B);
            7:  Instruction_reg <= (9'h04F);
            8:  Instruction_reg <= (9'h000);
            9:  Instruction_reg <= (9'h000);
            10: Instruction_reg <= (9'h000);
            11: Instruction_reg <= (9'h000);
            12: Instruction_reg <= (9'h000);
            13: Instruction_reg <= (9'h000);
            14: Instruction_reg <= (9'h000);
            default: Instruction_reg <= (9'h000);
        endcase*/
    end               
    
endmodule
