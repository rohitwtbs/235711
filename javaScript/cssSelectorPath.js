function generateSelector(el) {
    if (!(el instanceof Element)) return;
    var path = [];
    while (el.nodeType === Node.ELEMENT_NODE) {
        var selector = el.nodeName.toLowerCase();
        if (el.id) {
            selector += '#' + el.id;
        } else {
            var sib = el, nth = 1;
            while (sib.nodeType === Node.ELEMENT_NODE && (sib = sib.previousSibling) && nth++);
            selector += ":nth-child("+nth+")";
        }
        path.unshift(selector);
        el = el.parentNode;
    }
    return path.join(" > ");
}




















/*
Question 5
Write an implementation of a function called `generateSelector` to generate a CSS selector path of a DOM element.

Base structure:

function generateSelector(DOMNode) {
 //should return the CSS selector
}

Output:
For the given sample HTML, the possible selector for each DOM element is mentioned against it in the comments

<body>
	<div id="z"><!-- Possible CSS Selector Path : #z -->
		<span class="a">Empty span</span><!-- Possible CSS Selector Path : span:nth-of-type(1), NOTE: .a would give two elements if we choose that. -->
		<ul class="a b c"></ul><!-- Possible CSS Selector Path : .a.b.c -->
		<ul><!-- Possible CSS Selector Path : ul:nth-of-type(2) -->
			<li>1</li><!-- Possible CSS Selector Path : ul:nth-of-type(2) > li:nth-of-type(1) -->
			<li>2</li><!-- Possible CSS Selector Path : ul:nth-of-type(2) > li:nth-of-type(2) -->
			<li>3</li><!-- Possible CSS Selector Path : ul:nth-of-type(2) > li:nth-of-type(3) -->
		</ul>
	</div>
</body>
*/