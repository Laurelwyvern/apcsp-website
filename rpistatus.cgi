#!/bin/bash


echo -e "Content-type: text/html\n\n"

echo "<link href='/sp3a/style.css' rel='stylesheet' type='text/css' />"
echo "<h2>Which Pis Are Alive?</h2>"
echo "<pre> $(./rpistatus) </pre>"
