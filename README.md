# 4016 type CMOS Bilateral Switch Tester

## Requirements
- 4016 type ICs (these have many different names. 14016 is the same thing, just to name an example).
- An Arduino (I used an R3 but anything with 8 outputs and 4 inputs will do).
- 4 resistors between 1k and 10kOhm.
- A computer.

## Set-up
Flash the program, disconnect the Arduino from your computer and hook up the IC as follows.

(I tried to make a diagram but failed horribly, sorry...)

The pinout of the 4016 can be found [here](https://www.ti.com/lit/ds/symlink/cd4016b.pdf#page=2). This pinout is universal among all vendors.

<details>
<summary>Inputs of the 4016.</summary>
A_IN to pin D8<br>
B_IN to pin D9<br>
C_IN to pin D10<br>
D_IN to pin D11
</details>

<details>
<summary>Outputs of the 4016, pull these down to GND with a resistor.</summary>
A_OUT to pin A5<br>
B_OUT to pin A4<br>
C_OUT to pin A3<br>
D_OUT to pin A2
</details>

<details>
<summary>Control pins of the 4016.</summary>
A_CTL to pin D2<br>
B_CTL to pin D3<br>
C_CTL to pin D4<br>
D_CTL to pin D5
</details>

<details>
<summary>Other pins.</summary>
VDD to +5V<br>
VSS to GND
</details>

In the Arduino software, open the Serial Monitor. Then re-connect the Arduino.

## Interpreting a test
The Arduino will print some stuff in the serial console. It might look as follows:
```text
4016 type CMOS Quad Bilateral Switch tester by QOTF-Alexi.
Make sure all outputs are pulled down with a resistor.
Alternating pass-fail usually means no IC is inserted or that the IC is fully dead.
Checking 1 ON state: PASS
Checking 1 OFF state: PASS
Checking 2 ON state: PASS
Checking 2 OFF state: PASS
Checking 3 ON state: FAIL
Checking 3 OFF state: PASS
Checking 4 ON state: PASS
Checking 4 OFF state: FAIL
DONE TESTING. Insert next IC and press RESET.
```
In this case, we see that switch 3 (so that's switch C, I'll fix it later(tm)) is permanently stuck in the off position, while switch D is permanently stuck turned on. The others pass just fine.

So this chip failed and needs to be replaced. Do note that, in very rare cases, it might misbehave on one voltage level but not the other (these have a very wide input voltage range of 5-20V). But we can only test for 5V with an Arduino, unless you install a logic level converter I suppose.

## TODO
I don't think I'll do much with this code, but these are some ideas I will leave here.
- Changing the switch 1234 to ABCD in the output.
- Changing the output to just say PASS or FAIL once, or add it to the output.
- Making it run faster (it really does not need 1 second delays).
- Adding display support (if I'm REALLY bored).

## Alexandra has got you covered.
You can find more in the UNLICENSE file, but here's a short summary: This is free and unencumbered software released into the public domain.
In which way you reuse my code is up to you, but please consider improving it wherever you see fit.
While it is not forbidden, blatantly copying is almost never a good thing to do.
