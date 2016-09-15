#!/usr/bin/env ruby
require 'sinatra'

get '/' do
  erb :index
end

post '/' do
  @result = params
  erb :result
end

__END__
@@ index
<!doctype html>
<html>
<meta charset="UTF-8">
<h1>Hello, world!</h1>
<form method=post>
  title <input type=text name=title>
  <br>
  credentials.id <input type=text name="credntials[id]">
  credentials.id <input type=password name="credntials[pass]">
  <br>
  body <input type=text name=body>
  <input type=submit>
</form>

@@ result
<!doctype html>
<html>
<meta charset="UTF-8">
<h1>결과</h1>
<code><pre><%= @result %></pre></code>
