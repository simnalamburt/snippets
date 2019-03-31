// Internal Compiler Error
// ========
//
// How to reproduce:
//
//     $ fpc internal-compiler-error.pas -OoTAILREC
//     Free Pascal Compiler version 3.0.4 [2018/10/02] for x86_64
//     Copyright (c) 1993-2017 by Florian Klaempfl and others
//     Target OS: Darwin for x86_64
//     Compiling internal-compiler-error.pas
//     internal-compiler-error.pas(22,1) Fatal: Internal error 99080501
//     Fatal: Compilation aborted
//     Error: /usr/local/bin/ppcx64 returned an error exitcode
//
// Note: `-OoTAILREC` is part of `-O2`
//
// #### References
// - https://svn.freepascal.org/cgi-bin/viewvc.cgi/trunk/compiler/symdef.pas?revision=41804&view=markup#l3950
// - https://github.com/graemeg/freepascal/blob/83f91f2ed72d52abf57b2ede2d4161060fac374e/compiler/symdef.pas#L3950

procedure recursion(list: Array of Integer);
begin
  exit();

  // An error occurs as compiler attempts to tail call optimize this line.
  // You should change the input type of this function into pointer of array.
  recursion(list);
end;

var
  list: Array[0..3] of Integer;
begin
  recursion(list)
end.
