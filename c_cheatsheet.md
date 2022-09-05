# C 📖
[C Cheatsheet](https://github.com/venkat-ranganathan/projects/blob/gh-pages/Cheatsheet-c.pdf){:target="_blank"}
<?php
  $dir = '/absolute/path/to/my/directory/';
  $name = 'myPDF.pdf';
  exec("/bin/convert $dir$name $dir$name.png");
  print '<img src="$dir$name.png" />';
?>
