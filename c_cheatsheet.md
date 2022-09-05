# C 📖
[C Cheatsheet](https://github.com/venkat-ranganathan/projects/blob/gh-pages/Cheatsheet-c.pdf){:target="_blank"}
<?php
  $dir = '/venkat-ranganathan/projects/blob/gh-pages/';
  $name = 'Cheatsheet-c.pdf';
  exec("/bin/convert $dir$name $dir$name.png");
  print '<img src="$dir$name.png" />';
?>
