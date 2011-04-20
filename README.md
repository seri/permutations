Problem
=======

Given `n`, generate all permutations from the string of size `n` that starts 
with `'a'` to `char('a' + n)`

Solutions
=========

- [B.Heap's algorithm][cut-the-knot]
- [University of Exeter's algorithm][bearcave]
- [Bogomolny's algorithm][bearcave]
- *Spreading* is just natural backtracking
- [Johnson-Trotter's algorithm][trotter]
- [Factorial number system][wiki]
- [Inverse selection sort][wiki]
- *Injection* is a natural Haskell implementation
- Haskell also has a [builtin][builtin] function to generate permutations
- Someone on Haskell Cafe introduced an algorithm based on [selections][selections]

[bearcave]: http://www.bearcave.com/random_hacks/permute.html
[cut-the-knot]: http://www.cut-the-knot.org/do_you_know/AllPerm.shtml
[trotter]: http://www.cut-the-knot.org/Curriculum/Combinatorics/JohnsonTrotter.shtml
[wiki]: http://en.wikipedia.org/wiki/Factorial_number_system
[builtin]: http://haskell.org/ghc/docs/6.12.1/html/libraries/base-4.2.0.0/Data-List.html#v:permutations
[selections]: http://osdir.com/ml/lang.haskell.cafe/2002-06/msg00036.html

Benchmarking
============

Benchmarking is done for `n = 11`. Time measured in seconds.

On my desktop
-------------

<table>
<thead>
<tr>
	<th>Algorithm</th>
	<th>C++</th>
	<th>Lua</th>
	<th>Haskell</th>
</tr>
</thead>
<tbody>
<tr>
	<td>HeapPermute</td>
	<td>3</td>
	<td>54</td>
</tr>
<tr>
	<td>Exeter</td>
	<td>3</td>
	<td>59</td>
</tr>
<tr>
	<td>Bogomolny</td>
	<td>7</td>
	<td>60</td>
</tr>
<tr>
	<td>Spreading</td>
	<td>8</td>
	<td>63</td>
</tr>
<tr>
	<td>JohnsonTrotter</td>
	<td>9</td>
	<td>71</td>
</tr>
<tr>
	<td>InverseSelect</td>
	<td>15</td>
	<td>70</td>
</tr>
<tr>
	<td>Factoradic</td>
	<td>21</td>
	<td>84</td>
</tr>
<tr>
	<td>Builtin</td>
	<td> </td>
	<td> </td>
	<td>16</td>
</tr>
<tr>
	<td>Injection</td>
	<td> </td>
	<td> </td>
	<td>19</td>
</tr>
<tr>
	<td>Select</td>
	<td> </td>
	<td> </td>
	<td>22</td>
</tr>
</tbody>
</table>

On my laptop
------------ 

<table>
<thead>
<tr>
	<th>Algorithm</th>
	<th>C++</th>
	<th>Lua</th>
	<th>Haskell</th>
</tr>
</thead>
<tbody>
<tr>
	<td>HeapPermute</td>
	<td>44</td>
	<td> </td>
</tr>
<tr>
	<td>Exeter</td>
	<td>25</td>
	<td> </td>
</tr>
<tr>
	<td>Bogomolny</td>
	<td>26</td>
	<td> </td>
</tr>
<tr>
	<td>Spreading</td>
	<td>29</td>
	<td> </td>
</tr>
<tr>
	<td>JohnsonTrotter</td>
	<td>26</td>
	<td> </td>
</tr>
<tr>
	<td>InverseSelect</td>
	<td>42</td>
	<td> </td>
</tr>
<tr>
	<td>Factoradic</td>
	<td>51</td>
	<td> </td>
</tr>
<tr>
	<td>Builtin</td>
	<td> </td>
	<td> </td>
	<td>44</td>
</tr>
<tr>
	<td>Injection</td>
	<td> </td>
	<td> </td>
	<td>46</td>
</tr>
<tr>
	<td>Select</td>
	<td> </td>
	<td> </td>
	<td>49</td>
</tr>
</tbody>
</table>

Conclusion
==========

- HeapPermute is fastest
- Haskell performs OK 

Todo
----

- Explain HeapPermute

