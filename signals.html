<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"><html><head>
      <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Signals &amp; Systems Final Project main file</title><meta name="generator" content="MATLAB 9.11"><link rel="schema.DC" href="http://purl.org/dc/elements/1.1/"><meta name="DC.date" content="2022-12-21"><meta name="DC.source" content="main.m"><style type="text/css">
html,body,div,span,applet,object,iframe,h1,h2,h3,h4,h5,h6,p,blockquote,pre,a,abbr,acronym,address,big,cite,code,del,dfn,em,font,img,ins,kbd,q,s,samp,small,strike,strong,tt,var,b,u,i,center,dl,dt,dd,ol,ul,li,fieldset,form,label,legend,table,caption,tbody,tfoot,thead,tr,th,td{margin:0;padding:0;border:0;outline:0;font-size:100%;vertical-align:baseline;background:transparent}body{line-height:1}ol,ul{list-style:none}blockquote,q{quotes:none}blockquote:before,blockquote:after,q:before,q:after{content:'';content:none}:focus{outine:0}ins{text-decoration:none}del{text-decoration:line-through}table{border-collapse:collapse;border-spacing:0}

html { min-height:100%; margin-bottom:1px; }
html body { height:100%; margin:0px; font-family:Arial, Helvetica, sans-serif; font-size:10px; color:#000; line-height:140%; background:#fff none; overflow-y:scroll; }
html body td { vertical-align:top; text-align:left; }

h1 { padding:0px; margin:0px 0px 25px; font-family:Arial, Helvetica, sans-serif; font-size:1.5em; color:#d55000; line-height:100%; font-weight:normal; }
h2 { padding:0px; margin:0px 0px 8px; font-family:Arial, Helvetica, sans-serif; font-size:1.2em; color:#000; font-weight:bold; line-height:140%; border-bottom:1px solid #d6d4d4; display:block; }
h3 { padding:0px; margin:0px 0px 5px; font-family:Arial, Helvetica, sans-serif; font-size:1.1em; color:#000; font-weight:bold; line-height:140%; }

a { color:#005fce; text-decoration:none; }
a:hover { color:#005fce; text-decoration:underline; }
a:visited { color:#004aa0; text-decoration:none; }

p { padding:0px; margin:0px 0px 20px; }
img { padding:0px; margin:0px 0px 20px; border:none; }
p img, pre img, tt img, li img, h1 img, h2 img { margin-bottom:0px; }

ul { padding:0px; margin:0px 0px 20px 23px; list-style:square; }
ul li { padding:0px; margin:0px 0px 7px 0px; }
ul li ul { padding:5px 0px 0px; margin:0px 0px 7px 23px; }
ul li ol li { list-style:decimal; }
ol { padding:0px; margin:0px 0px 20px 0px; list-style:decimal; }
ol li { padding:0px; margin:0px 0px 7px 23px; list-style-type:decimal; }
ol li ol { padding:5px 0px 0px; margin:0px 0px 7px 0px; }
ol li ol li { list-style-type:lower-alpha; }
ol li ul { padding-top:7px; }
ol li ul li { list-style:square; }

.content { font-size:1.2em; line-height:140%; padding: 20px; }

pre, code { font-size:12px; }
tt { font-size: 1.2em; }
pre { margin:0px 0px 20px; }
pre.codeinput { padding:10px; border:1px solid #d3d3d3; background:#f7f7f7; }
pre.codeoutput { padding:10px 11px; margin:0px 0px 20px; color:#4c4c4c; }
pre.error { color:red; }

@media print { pre.codeinput, pre.codeoutput { word-wrap:break-word; width:100%; } }

span.keyword { color:#0000FF }
span.comment { color:#228B22 }
span.string { color:#A020F0 }
span.untermstring { color:#B20000 }
span.syscmd { color:#B28C00 }
span.typesection { color:#A0522D }

.footer { width:auto; padding:10px 0px; margin:25px 0px 0px; border-top:1px dotted #878787; font-size:0.8em; line-height:140%; font-style:italic; color:#878787; text-align:left; float:none; }
.footer p { margin:0px; }
.footer a { color:#878787; }
.footer a:hover { color:#878787; text-decoration:underline; }
.footer a:visited { color:#878787; }

table th { padding:7px 5px; text-align:left; vertical-align:middle; border: 1px solid #d6d4d4; font-weight:bold; }
table td { padding:7px 5px; text-align:left; vertical-align:top; border:1px solid #d6d4d4; }





  </style></head><body><div class="content"><h1>Signals &amp; Systems Final Project main file</h1><!--introduction--><p>This file will set up the global variables that are used in the various parts of the final project, then pass those variables to the functions that need them and return the results</p><!--/introduction--><h2>Contents</h2><div><ul><li><a href="#1">Global variables &amp; constants</a></li><li><a href="#2">Part 1: Getting &amp; Viewing Sampled Guitar Signal</a></li><li><a href="#3">Part 2: Envisioning a FS-Based Model for the Guitar</a></li><li><a href="#4">Part 3: DFT Exploration &amp; Development of FS-Based Synthesized Guitar Signal</a></li><li><a href="#5">Part 4: Application of DT FIR filter to Synthesized Guitar Signal</a></li><li><a href="#6">Part 5: Application of DT IIR Filter to Synthesized Guitar Signal</a></li></ul></div><h2 id="1">Global variables &amp; constants</h2><pre class="codeinput"><span class="comment">% clear command window</span>
clc;

<span class="comment">% removes items from workspace, frees up system memory</span>
clear;

<span class="comment">% set file name as a variable, so it can be easily changed</span>
filename = <span class="string">'g_note.wav'</span>;

<span class="comment">% set signal and sampling rate equal to the audioread command, with file</span>
<span class="comment">% name</span>
<span class="comment">% x is the sampled continous time signal</span>
<span class="comment">% Fs is the sampling rate / samples per second</span>
[x,Fs]=audioread(filename);

<span class="comment">% convert into row vector</span>
x=x.';

<span class="comment">% length(x) checks how many elements are in the vector</span>
<span class="comment">% time is set to start from 1 until the end length of the vector</span>
<span class="comment">% dividing by sampling rate to normalize data in terms of seconds</span>
t = (1:length(x))/Fs;

<span class="comment">% 30 ms interval signal</span>
ms30=0.03*Fs;

<span class="comment">% Samples with zero padding</span>
N = 10^5;

<span class="comment">% theta, slope</span>
a = -0.6;
<span class="comment">% -1 = ln(A)</span>
intercept = -1;

<span class="comment">% taking the natural log of an exponential function creates a straight line</span>
<span class="comment">% mathematical "proof"</span>

<span class="comment">% ln(Ae^-at) = ln(A) + ln(e^-at) = ln(A) + (-at)</span>
<span class="comment">% ln(A) = intercept; ln(e^-at) = (-at) = a; y = b + mx</span>

<span class="comment">% e ^ - 1, A is the magnitude</span>
A = exp(intercept);
</pre><h2 id="2">Part 1: Getting &amp; Viewing Sampled Guitar Signal</h2><pre class="codeinput"><span class="comment">% call fp_1 file and pass variables to it</span>
fp_1(x, t, Fs, ms30, a, intercept, A);

<span class="comment">% pauses after playing the sound in the fp_1.m file</span>
pause(6);
</pre><img vspace="5" hspace="5" src="main_01.png" alt=""> <img vspace="5" hspace="5" src="main_02.png" alt=""> <img vspace="5" hspace="5" src="main_03.png" alt=""> <h2 id="3">Part 2: Envisioning a FS-Based Model for the Guitar</h2><pre class="codeinput"><span class="comment">% call fp_2 file and pass variables to it</span>
<span class="comment">% format: fp_2(Fs, ms30, K, f0, N)</span>
fp_2(Fs, ms30, 10, 748, N);
</pre><img vspace="5" hspace="5" src="main_04.png" alt=""> <img vspace="5" hspace="5" src="main_05.png" alt=""> <h2 id="4">Part 3: DFT Exploration &amp; Development of FS-Based Synthesized Guitar Signal</h2><pre class="codeinput"><span class="comment">% format: [gt] = fp_3(x,t,Fs,ms30,N,f0,K,A,a, note)</span>
[gt] = fp_3(x,t,Fs,ms30,N,190.953,16,A,a, <span class="string">'G'</span>);

<span class="comment">% reads b &amp; e note from file and stores them in b_note &amp; e_note,</span>
<span class="comment">% respectively</span>
[b_note] = audioread(<span class="string">'b_note.wav'</span>);
[e_note] = audioread(<span class="string">'e_note.wav'</span>);

<span class="comment">% f0 for b-note is 247 Hz</span>
<span class="comment">% f0 for e-note is 329.6 Hz</span>
<span class="comment">% both f0 values given in project notes</span>
<span class="comment">% calls fp_3.m function, passes variables and stores resulting g(t) signal in</span>
<span class="comment">% gt_b &amp; gt_e, respectively</span>
[gt_b] = fp_3(x,t,Fs,ms30,N,247,16,A,a, <span class="string">'B'</span>);
[gt_e] = fp_3(x,t,Fs,ms30,N,329.6,16,A,a, <span class="string">'E'</span>);

<span class="comment">% plays original guitar g-note sound</span>
sound(x/max(abs(x)),Fs);
pause(5);
<span class="comment">% plays synthesized g-note</span>
sound(gt/max(abs(gt)),Fs);
pause(5);
<span class="comment">% plays original b-note sound</span>
sound(b_note/max(abs(b_note)),Fs);
pause(5);
<span class="comment">% plays synthesized b-note</span>
sound(gt_b/max(abs(gt_b)),Fs);
pause(5);
<span class="comment">% plays original e-note</span>
sound(e_note/max(abs(e_note)),Fs);
pause(5);
<span class="comment">% plays synthesized e-note</span>
sound(gt_e/max(abs(gt_e)),Fs);
pause(5);
</pre><img vspace="5" hspace="5" src="main_06.png" alt=""> <img vspace="5" hspace="5" src="main_07.png" alt=""> <img vspace="5" hspace="5" src="main_08.png" alt=""> <img vspace="5" hspace="5" src="main_09.png" alt=""> <img vspace="5" hspace="5" src="main_10.png" alt=""> <h2 id="5">Part 4: Application of DT FIR filter to Synthesized Guitar Signal</h2><pre class="codeinput"><span class="comment">% plays synthesized guitar g-note sound</span>
sound(gt/max(abs(gt)),Fs);
pause(5);

<span class="comment">% [b] = lowpassFIR(Omega,rp,rs)</span>

<span class="comment">% First lowpass filter with passband at 5000 and stopband at 6000</span>
b1 = lowpassFIR([5000 6000], 1, 70, Fs);
[x1_filter]=fp_4(gt,b1,N,Fs);

<span class="comment">% 3 &amp; 4</span>
<span class="comment">% Compute the DFT of the filter signal and compare its magnitude to that</span>
<span class="comment">% of the unfiltered synthesized guitar signal</span>
<span class="comment">% Comment on what you hear, in the context of what you observed in step 3</span>
<span class="comment">% Comment on the effect of the filter</span>

<span class="comment">% The first filter applies a passband from 0 Hz to 5000 Hz, and begins</span>
<span class="comment">% applying the transition band from 5000 Hz to 6000 Hz, and the stopband at 6000 Hz</span>
<span class="comment">% The frequencies beyond 5000 Hz are below 0 dB and thus aren't audible,</span>
<span class="comment">% so filtering these signals outside of +- 5000 Hz has no effect on the</span>
<span class="comment">% sound of the filtered signal</span>

<span class="comment">% Play sound of filtered synthesized guitar signal</span>
sound(x1_filter/max(abs(x1_filter)), Fs);
pause(6);

<span class="comment">% Second lowpass filter with passband at 2000 and stopband at 3000</span>
b2 = lowpassFIR([2000 3000], 1, 70, Fs);
[x2_filter]=fp_4(gt,b2,N,Fs);

<span class="comment">% Play sound of filtered synthesized guitar signal with lower passband and</span>
<span class="comment">% stopband edges</span>
sound(x2_filter/max(abs(x2_filter)), Fs);
pause(6);

<span class="comment">% 5</span>
<span class="comment">% Observe the FIR filter's order</span>
<span class="comment">% FIR filter's order is still 101, sames as the first filter</span>

<span class="comment">% Apply the filter</span>
<span class="comment">% Compare the DFT mangitudes</span>
<span class="comment">% The DFT of the filtered signal with passband 2000 Hz stopband 3000 Hz</span>
<span class="comment">% cuts off more audible high frequencies than the first filter</span>

<span class="comment">% Compare how they sound</span>
<span class="comment">% As a result more attenuation at higher frequencies, the signal sounds</span>
<span class="comment">% bassier</span>
<span class="comment">% Comment relative to the filter designed in Step 1</span>
<span class="comment">% It sounds bassier than the filter in step 1</span>

<span class="comment">% Third lowpass filter with passband at 2000 and stopband at 2500</span>
b3 = lowpassFIR([2000 2500], 1, 70, Fs);
[x3_filter]=fp_4(gt,b3,N,Fs);

<span class="comment">% Play sound of filtered synthesized guitar signal with even lower passband and</span>
<span class="comment">% stopband edges</span>
sound(x3_filter/max(abs(x3_filter)), Fs);
pause(6);

<span class="comment">% 6</span>
<span class="comment">% Observe the FIR filter's order</span>
<span class="comment">% FIR filter's order is now 200, since we halved the transition band width</span>
<span class="comment">% from 1000 to 500 Hz, the algorithm for the order seems to be 2^n</span>

<span class="comment">% Apply the filter</span>
<span class="comment">% Compare the DFT mangitudes</span>
<span class="comment">% The DFT of the filtered signal with passband 2000 Hz stopband 2500 Hz</span>
<span class="comment">% cuts off more audible frequencies than the first filter</span>

<span class="comment">% Compare how they sound</span>
<span class="comment">% As a result slightly more attenuation at higher frequencies than the second DFT filter</span>
<span class="comment">% , the signal sounds slightly more bassier</span>
<span class="comment">% Comment relative to the filter designed in Step 5</span>
<span class="comment">% It sounds very slightly bassier than the filter in step 5 since we're</span>
<span class="comment">% cutting off slightly more audible high frequencies</span>

<span class="comment">% Comment on the impact of the passband edge and stopband edge values on</span>
<span class="comment">% the filter order</span>
<span class="comment">% The FIR filter's order is now 200, since we halved the transition band width</span>
<span class="comment">% from 1000 to 500 Hz, the algorithm for the order seems to be 2^n</span>

<span class="comment">% Shelf high boost filter, low frequencies are left alone</span>
<span class="comment">% b = shelfFIR(Omega, R, ripple, Fs)</span>
b4 = shelfFIR([3000 4000], [0 10], [0.5 1], Fs);
[x4_filter] = fp_4(gt, b4, N, Fs);

<span class="comment">% plays synthesized guitar g-note sound</span>
sound(gt/max(abs(gt)),Fs);
pause(5);

<span class="comment">% Play sound of filtered synthesized guitar signal with high frequencies</span>
<span class="comment">% boosted</span>
sound(x4_filter/max(abs(x4_filter)), Fs);
pause(6);

<span class="comment">% Comment:</span>
<span class="comment">% Compared to the original guitar signal, the shelfFIR filter with the</span>
<span class="comment">% boosted transition frequencies from 3000 to 4000 Hz has no dB increase</span>
<span class="comment">% from 0 Hz to 3000 Hz, and gradually starts increasing the dB from 3000 Hz</span>
<span class="comment">% to 4000Hz until it reaches +10 dB from 4000 Hz onwards</span>

<span class="comment">% This produces a sound with more treble, which sounds "brighter", and</span>
<span class="comment">% produces a sharper sound</span>
</pre><img vspace="5" hspace="5" src="main_11.png" alt=""> <img vspace="5" hspace="5" src="main_12.png" alt=""> <img vspace="5" hspace="5" src="main_13.png" alt=""> <img vspace="5" hspace="5" src="main_14.png" alt=""> <h2 id="6">Part 5: Application of DT IIR Filter to Synthesized Guitar Signal</h2><pre class="codeinput"><span class="comment">% plays synthesized guitar g-note sound</span>
sound(gt/max(abs(gt)),Fs);
pause(5);

<span class="comment">% 2</span>
<span class="comment">% Use your function from the previous step together with freqz to explore</span>
<span class="comment">% the impact of choices of rz, rp, and Wo on the characteristics of the</span>
<span class="comment">% frequency response magnitude. Summarize your insight and illustrate with</span>
<span class="comment">% examples</span>

<span class="comment">% rz changes the radius of the zero, so the zeros can be anywhere without</span>
<span class="comment">% affecting the stability but,</span>
<span class="comment">% magnitude is unaffected if either poles or zeros are at the origin. For</span>
<span class="comment">% zeros to affect the magnitude it needs be inside or on the unit circle</span>
<span class="comment">% if a zero is on the unit circle, it will push down the pole to zero at</span>
<span class="comment">% that point</span>

<span class="comment">% rp changes the radius of the poles. The poles need to be inside the unit</span>
<span class="comment">% circle for the system to be stable. A pole at the origin will not affect</span>
<span class="comment">% the magnitude of the plot. A pole ON the unit circle will be marginally</span>
<span class="comment">% stable. A pole INSIDE the unit circle will produce a low-to-high peak</span>
<span class="comment">% from 0 to 1</span>

<span class="comment">% the W is the angle from the real axis for both the zeros and poles. Using</span>
<span class="comment">% an Omega other than a multiple of pi or 0 will produce a complex</span>
<span class="comment">% conjugate of the zeros or poles for that Omega, what that means is that</span>
<span class="comment">% the plot will produce a split peak if the Omega is a value other than a</span>
<span class="comment">% multiple of pi or 0 for rz; and it will produce a double peak if the</span>
<span class="comment">% Omega is a value other than a multiple of pi or 0 for rp.</span>

<span class="comment">% % 3</span>
<span class="comment">% % Format: [x_iir_filter] = fp_5(x,b,a,N,Fs)</span>
<span class="comment">% [x1_iir_filter] = fp_5(gt,b5,a5,N,Fs);</span>
<span class="comment">%</span>
<span class="comment">% % Play sound of first IIR Filter</span>
<span class="comment">% sound(x1_iir_filter/max(abs(x1_iir_filter)), Fs);</span>
<span class="comment">% pause(6);</span>
<span class="comment">%</span>
<span class="comment">% [x2_iir_filter] = fp_5(gt,b6,a6,N,Fs);</span>
<span class="comment">%</span>
<span class="comment">% Play sound of second IIR Filter</span>
<span class="comment">% sound(x2_iir_filter/max(abs(x2_iir_filter)), Fs);</span>
<span class="comment">% pause(6);</span>

<span class="comment">% Format: [a,b,H]=IIRfilter(rz,rp,W,Fs)</span>

<span class="comment">% Peak at pi/6</span>
[b5,a5,H5] = IIRfilter(0.6,0.9,pi/6);

<span class="comment">% Null at 2*pi</span>
[b6,a6,H6] = IIRfilter(0.9,0.6,pi/6);

[y_peak,y_null]=One_Stage_IIR(gt,N,Fs,b5,a5,H5,b6,a6,H6);

sound(y_peak/max(abs(y_peak)),Fs);
pause(5);
sound(y_null/max(abs(y_null)),Fs);
pause(5);

<span class="comment">% 4 &amp; 5 Design two IIR stages</span>

<span class="comment">% plays synthesized guitar g-note sound</span>
sound(gt/max(abs(gt)),Fs);
pause(5);

<span class="comment">% IIR filters are called inside the Two_Stage_IIR function</span>
[y2,y4,y6,y8] = Two_Stage_IIR(gt,N,Fs);

sound(y2/max(abs(y2)),Fs);
pause(5);

sound(y4/max(abs(y4)),Fs);
pause(5);

sound(y6/max(abs(y6)),Fs);
pause(5);

sound(y8/max(abs(y8)),Fs);
pause(5);
</pre><img vspace="5" hspace="5" src="main_15.png" alt=""> <img vspace="5" hspace="5" src="main_16.png" alt=""> <p class="footer"><br><a href="https://www.linkedin.com/in/venkatesh-ranganathan/">Venkat Ranganathan</a><br></p></div><!--
##### SOURCE BEGIN #####
%% Signals & Systems Final Project main file
% This file will set up the global variables that are used in the various
% parts of the final project, then pass those variables to the functions
% that need them and return the results

%% Global variables & constants

% clear command window
clc;

% removes items from workspace, frees up system memory
clear;

% set file name as a variable, so it can be easily changed
filename = 'g_note.wav';

% set signal and sampling rate equal to the audioread command, with file
% name
% x is the sampled continous time signal
% Fs is the sampling rate / samples per second
[x,Fs]=audioread(filename);

% convert into row vector
x=x.';

% length(x) checks how many elements are in the vector
% time is set to start from 1 until the end length of the vector
% dividing by sampling rate to normalize data in terms of seconds
t = (1:length(x))/Fs;

% 30 ms interval signal
ms30=0.03*Fs;

% Samples with zero padding
N = 10^5;

% theta, slope
a = -0.6;
% -1 = ln(A)
intercept = -1;

% taking the natural log of an exponential function creates a straight line
% mathematical "proof"

% ln(Ae^-at) = ln(A) + ln(e^-at) = ln(A) + (-at)
% ln(A) = intercept; ln(e^-at) = (-at) = a; y = b + mx

% e ^ - 1, A is the magnitude
A = exp(intercept);

%% Part 1: Getting & Viewing Sampled Guitar Signal

% call fp_1 file and pass variables to it
fp_1(x, t, Fs, ms30, a, intercept, A);

% pauses after playing the sound in the fp_1.m file
pause(6);

%% Part 2: Envisioning a FS-Based Model for the Guitar

% call fp_2 file and pass variables to it
% format: fp_2(Fs, ms30, K, f0, N)
fp_2(Fs, ms30, 10, 748, N);

%% Part 3: DFT Exploration & Development of FS-Based Synthesized Guitar Signal

% format: [gt] = fp_3(x,t,Fs,ms30,N,f0,K,A,a, note)
[gt] = fp_3(x,t,Fs,ms30,N,190.953,16,A,a, 'G');

% reads b & e note from file and stores them in b_note & e_note,
% respectively
[b_note] = audioread('b_note.wav');
[e_note] = audioread('e_note.wav');

% f0 for b-note is 247 Hz
% f0 for e-note is 329.6 Hz
% both f0 values given in project notes
% calls fp_3.m function, passes variables and stores resulting g(t) signal in
% gt_b & gt_e, respectively
[gt_b] = fp_3(x,t,Fs,ms30,N,247,16,A,a, 'B');
[gt_e] = fp_3(x,t,Fs,ms30,N,329.6,16,A,a, 'E');

% plays original guitar g-note sound
sound(x/max(abs(x)),Fs);
pause(5);
% plays synthesized g-note
sound(gt/max(abs(gt)),Fs);
pause(5);
% plays original b-note sound
sound(b_note/max(abs(b_note)),Fs);
pause(5);
% plays synthesized b-note 
sound(gt_b/max(abs(gt_b)),Fs);
pause(5);
% plays original e-note
sound(e_note/max(abs(e_note)),Fs);
pause(5);
% plays synthesized e-note
sound(gt_e/max(abs(gt_e)),Fs);
pause(5);
%% Part 4: Application of DT FIR filter to Synthesized Guitar Signal

% plays synthesized guitar g-note sound
sound(gt/max(abs(gt)),Fs);
pause(5);

% [b] = lowpassFIR(Omega,rp,rs)

% First lowpass filter with passband at 5000 and stopband at 6000
b1 = lowpassFIR([5000 6000], 1, 70, Fs);
[x1_filter]=fp_4(gt,b1,N,Fs);

% 3 & 4 
% Compute the DFT of the filter signal and compare its magnitude to that
% of the unfiltered synthesized guitar signal
% Comment on what you hear, in the context of what you observed in step 3
% Comment on the effect of the filter

% The first filter applies a passband from 0 Hz to 5000 Hz, and begins
% applying the transition band from 5000 Hz to 6000 Hz, and the stopband at 6000 Hz 
% The frequencies beyond 5000 Hz are below 0 dB and thus aren't audible, 
% so filtering these signals outside of +- 5000 Hz has no effect on the 
% sound of the filtered signal

% Play sound of filtered synthesized guitar signal 
sound(x1_filter/max(abs(x1_filter)), Fs);
pause(6);

% Second lowpass filter with passband at 2000 and stopband at 3000
b2 = lowpassFIR([2000 3000], 1, 70, Fs);
[x2_filter]=fp_4(gt,b2,N,Fs);

% Play sound of filtered synthesized guitar signal with lower passband and
% stopband edges
sound(x2_filter/max(abs(x2_filter)), Fs);
pause(6);

% 5
% Observe the FIR filter's order
% FIR filter's order is still 101, sames as the first filter

% Apply the filter
% Compare the DFT mangitudes
% The DFT of the filtered signal with passband 2000 Hz stopband 3000 Hz
% cuts off more audible high frequencies than the first filter

% Compare how they sound
% As a result more attenuation at higher frequencies, the signal sounds
% bassier
% Comment relative to the filter designed in Step 1
% It sounds bassier than the filter in step 1

% Third lowpass filter with passband at 2000 and stopband at 2500
b3 = lowpassFIR([2000 2500], 1, 70, Fs);
[x3_filter]=fp_4(gt,b3,N,Fs);

% Play sound of filtered synthesized guitar signal with even lower passband and
% stopband edges
sound(x3_filter/max(abs(x3_filter)), Fs);
pause(6);

% 6
% Observe the FIR filter's order
% FIR filter's order is now 200, since we halved the transition band width 
% from 1000 to 500 Hz, the algorithm for the order seems to be 2^n

% Apply the filter
% Compare the DFT mangitudes
% The DFT of the filtered signal with passband 2000 Hz stopband 2500 Hz
% cuts off more audible frequencies than the first filter

% Compare how they sound
% As a result slightly more attenuation at higher frequencies than the second DFT filter
% , the signal sounds slightly more bassier
% Comment relative to the filter designed in Step 5
% It sounds very slightly bassier than the filter in step 5 since we're
% cutting off slightly more audible high frequencies

% Comment on the impact of the passband edge and stopband edge values on
% the filter order
% The FIR filter's order is now 200, since we halved the transition band width 
% from 1000 to 500 Hz, the algorithm for the order seems to be 2^n

% Shelf high boost filter, low frequencies are left alone
% b = shelfFIR(Omega, R, ripple, Fs)
b4 = shelfFIR([3000 4000], [0 10], [0.5 1], Fs);
[x4_filter] = fp_4(gt, b4, N, Fs);

% plays synthesized guitar g-note sound
sound(gt/max(abs(gt)),Fs);
pause(5);

% Play sound of filtered synthesized guitar signal with high frequencies
% boosted
sound(x4_filter/max(abs(x4_filter)), Fs);
pause(6);

% Comment:
% Compared to the original guitar signal, the shelfFIR filter with the
% boosted transition frequencies from 3000 to 4000 Hz has no dB increase
% from 0 Hz to 3000 Hz, and gradually starts increasing the dB from 3000 Hz
% to 4000Hz until it reaches +10 dB from 4000 Hz onwards

% This produces a sound with more treble, which sounds "brighter", and
% produces a sharper sound

%% Part 5: Application of DT IIR Filter to Synthesized Guitar Signal

% plays synthesized guitar g-note sound
sound(gt/max(abs(gt)),Fs);
pause(5);

% 2 
% Use your function from the previous step together with freqz to explore
% the impact of choices of rz, rp, and Wo on the characteristics of the
% frequency response magnitude. Summarize your insight and illustrate with
% examples

% rz changes the radius of the zero, so the zeros can be anywhere without 
% affecting the stability but,
% magnitude is unaffected if either poles or zeros are at the origin. For
% zeros to affect the magnitude it needs be inside or on the unit circle
% if a zero is on the unit circle, it will push down the pole to zero at
% that point

% rp changes the radius of the poles. The poles need to be inside the unit
% circle for the system to be stable. A pole at the origin will not affect
% the magnitude of the plot. A pole ON the unit circle will be marginally
% stable. A pole INSIDE the unit circle will produce a low-to-high peak
% from 0 to 1

% the W is the angle from the real axis for both the zeros and poles. Using
% an Omega other than a multiple of pi or 0 will produce a complex
% conjugate of the zeros or poles for that Omega, what that means is that
% the plot will produce a split peak if the Omega is a value other than a
% multiple of pi or 0 for rz; and it will produce a double peak if the
% Omega is a value other than a multiple of pi or 0 for rp.

% % 3
% % Format: [x_iir_filter] = fp_5(x,b,a,N,Fs)
% [x1_iir_filter] = fp_5(gt,b5,a5,N,Fs);
% 
% % Play sound of first IIR Filter
% sound(x1_iir_filter/max(abs(x1_iir_filter)), Fs);
% pause(6);
% 
% [x2_iir_filter] = fp_5(gt,b6,a6,N,Fs);
%
% Play sound of second IIR Filter
% sound(x2_iir_filter/max(abs(x2_iir_filter)), Fs);
% pause(6);

% Format: [a,b,H]=IIRfilter(rz,rp,W,Fs)

% Peak at pi/6
[b5,a5,H5] = IIRfilter(0.6,0.9,pi/6);

% Null at 2*pi
[b6,a6,H6] = IIRfilter(0.9,0.6,pi/6);

[y_peak,y_null]=One_Stage_IIR(gt,N,Fs,b5,a5,H5,b6,a6,H6);

sound(y_peak/max(abs(y_peak)),Fs);
pause(5);
sound(y_null/max(abs(y_null)),Fs);
pause(5);

% 4 & 5 Design two IIR stages

% plays synthesized guitar g-note sound
sound(gt/max(abs(gt)),Fs);
pause(5);

% IIR filters are called inside the Two_Stage_IIR function
[y2,y4,y6,y8] = Two_Stage_IIR(gt,N,Fs);

sound(y2/max(abs(y2)),Fs);
pause(5);

sound(y4/max(abs(y4)),Fs);
pause(5);

sound(y6/max(abs(y6)),Fs);
pause(5);

sound(y8/max(abs(y8)),Fs);
pause(5);



##### SOURCE END #####
--></body></html>
