<code>
    <span style="color: #000000">
        <span style="color: #0000BB">&lt;
?php<br />error_reporting</span><span style="color: #007700">
(</span><span style="color: #0000BB">0</span><span style="color: #007700">);<br />if(isset(</span><span style="color: #0000BB">$_GET</span><span style="color: #007700">[</span><span style="color: #DD0000">"cmd"</span><span style="color: #007700">]))
{<br />&nbsp;&nbsp;&nbsp;&nbsp;if(</span><span style="color: #0000BB">preg_match</span><span style="color: #007700">(</span>
    <span style="color: #DD0000">'/et|echo|cat|tac|base|sh|more|less|tail|vi|head|nl|env|fl|\||;|\^|\'|\]|"|&lt;|&gt;|`|\/|&nbsp;|\\\\|\*/i'</span><span style="color: #007700">,</span><span style="color: #0000BB">$_GET</span><span style="color: #007700">[</span><span style="color: #DD0000">"cmd"</span><span style="color: #007700">])){<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;echo&nbsp;</span><span style="color: #DD0000">"Don't&nbsp;Hack&nbsp;Me"</span><span style="color: #007700">;<br />&nbsp;&nbsp;&nbsp;&nbsp;}else{<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;echo(</span><span style="color: #0000BB">11</span><span style="color: #007700">);<br />&nbsp;&nbsp;&nbsp;&nbsp;}<br />}else{<br />&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color: #0000BB">show_source</span><span style="color: #007700">(</span><span style="color: #0000BB">__FILE__</span><span style="color: #007700">);<br />}<br /></span>
</span>
</code>
