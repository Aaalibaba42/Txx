#pragma once

#include "literals/unsigned8.hh"

// Control characters (0-31)
using c_NUL = u8_0;   // Null
using c_SOH = u8_1;   // Start of Heading
using c_STX = u8_2;   // Start of Text
using c_ETX = u8_3;   // End of Text
using c_EOT = u8_4;   // End of Transmission
using c_ENQ = u8_5;   // Enquiry
using c_ACK = u8_6;   // Acknowledge
using c_BEL = u8_7;   // Bell
using c_BS = u8_8;    // Backspace
using c_TAB = u8_9;   // Horizontal Tab
using c_LF = u8_10;   // Line Feed (newline)
using c_VT = u8_11;   // Vertical Tab
using c_FF = u8_12;   // Form Feed
using c_CR = u8_13;   // Carriage Return
using c_SO = u8_14;   // Shift Out
using c_SI = u8_15;   // Shift In
using c_DLE = u8_16;  // Data Link Escape
using c_DC1 = u8_17;  // Device Control 1
using c_DC2 = u8_18;  // Device Control 2
using c_DC3 = u8_19;  // Device Control 3
using c_DC4 = u8_20;  // Device Control 4
using c_NAK = u8_21;  // Negative Acknowledge
using c_SYN = u8_22;  // Synchronous Idle
using c_ETB = u8_23;  // End of Transmission Block
using c_CAN = u8_24;  // Cancel
using c_EM = u8_25;   // End of Medium
using c_SUB = u8_26;  // Substitute
using c_ESC = u8_27;  // Escape
using c_FS = u8_28;   // File Separator
using c_GS = u8_29;   // Group Separator
using c_RS = u8_30;   // Record Separator
using c_US = u8_31;   // Unit Separator

// Printable characters (32-126)
using c_Space = u8_32;        // ' '
using c_Bang = u8_33;         // '!'
using c_DQuote = u8_34;       // '"'
using c_Hash = u8_35;         // '#'
using c_Dollar = u8_36;       // '$'
using c_Percent = u8_37;      // '%'
using c_Amp = u8_38;          // '&'
using c_SQuote = u8_39;       // '\''
using c_LPar = u8_40;         // '('
using c_RPar = u8_41;         // ')'
using c_Star = u8_42;         // '*'
using c_Plus = u8_43;         // '+'
using c_Comma = u8_44;        // ','
using c_Minus = u8_45;        // '-'
using c_Dot = u8_46;          // '.'
using c_Slash = u8_47;        // '/'

// Digits (48-57)
using c_0 = u8_48;
using c_1 = u8_49;
using c_2 = u8_50;
using c_3 = u8_51;
using c_4 = u8_52;
using c_5 = u8_53;
using c_6 = u8_54;
using c_7 = u8_55;
using c_8 = u8_56;
using c_9 = u8_57;

// Punctuation (58-64)
using c_Colon = u8_58;        // ':'
using c_Semi = u8_59;         // ';'
using c_Lt = u8_60;           // '<'
using c_Eq = u8_61;           // '='
using c_Gt = u8_62;           // '>'
using c_Question = u8_63;     // '?'
using c_At = u8_64;           // '@'

// Uppercase letters (65-90)
using c_A = u8_65;
using c_B = u8_66;
using c_C = u8_67;
using c_D = u8_68;
using c_E = u8_69;
using c_F = u8_70;
using c_G = u8_71;
using c_H = u8_72;
using c_I = u8_73;
using c_J = u8_74;
using c_K = u8_75;
using c_L = u8_76;
using c_M = u8_77;
using c_N = u8_78;
using c_O = u8_79;
using c_P = u8_80;
using c_Q = u8_81;
using c_R = u8_82;
using c_S = u8_83;
using c_T = u8_84;
using c_U = u8_85;
using c_V = u8_86;
using c_W = u8_87;
using c_X = u8_88;
using c_Y = u8_89;
using c_Z = u8_90;

// Punctuation (91-96)
using c_LBracket = u8_91;     // '['
using c_BSlash = u8_92;       // '\'
using c_RBracket = u8_93;     // ']'
using c_Caret = u8_94;        // '^'
using c_Under = u8_95;        // '_'
using c_Backtick = u8_96;     // '`'

// Lowercase letters (97-122)
using c_a = u8_97;
using c_b = u8_98;
using c_c = u8_99;
using c_d = u8_100;
using c_e = u8_101;
using c_f = u8_102;
using c_g = u8_103;
using c_h = u8_104;
using c_i = u8_105;
using c_j = u8_106;
using c_k = u8_107;
using c_l = u8_108;
using c_m = u8_109;
using c_n = u8_110;
using c_o = u8_111;
using c_p = u8_112;
using c_q = u8_113;
using c_r = u8_114;
using c_s = u8_115;
using c_t = u8_116;
using c_u = u8_117;
using c_v = u8_118;
using c_w = u8_119;
using c_x = u8_120;
using c_y = u8_121;
using c_z = u8_122;

// Punctuation (123-126)
using c_LBrace = u8_123;      // '{'
using c_Pipe = u8_124;        // '|'
using c_RBrace = u8_125;      // '}'
using c_Tilde = u8_126;       // '~'

// DEL (127)
using c_DEL = u8_127;

