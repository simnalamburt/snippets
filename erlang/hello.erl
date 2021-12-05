-module(hello).
-export([hello/0]).

hello() ->
  io:format("~s~n", ["Hello world!"]).
