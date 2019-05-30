var xmlhttp;

function loadXMLDoc(pid) {
	xmlhttp = getXMLHttpObject();
	if(xmlhttp == null) {
		alert("No XMLHttp support.");
		return;
	}

	var url = "getxmlcourses.php";
	url = url + "?q=" + pid;
	url = url + "&sid=" + Math.random();

	xmlhttp.onreadystatechange=stateChanged;
	xmlhttp.open("GET", url, true);
	xmlhttp.send();
}

function stateChanged() {
	if(xmlhttp.readyState == 4 && xmlhttp.status == 200) {
		var xml, token, txt;

		xml = xmlhttp.responseXML.documentElement.getElementsByTagName("course");

		txt = "<table border='1'><tr><th>Course ID</th><th>Course Name</th></tr>";

		for(var i = 0; i < xml.length; i++) {
			txt = txt + "<tr>";
			token = xml[i].getElementsByTagName("cid");
			try {
				txt = txt + "<td>" +
					token[0].firstChild.nodeValue + "</td>";
			}
			catch(er) {
				txt = txt + "<td>&nbsp</td>";
			}

			token = xml[i].getElementsByTagName("cname");
			try {
				txt = txt + "<td>" +
					token[0].firstChild.nodeValue + "</td>";
			}
			catch(er) {
				txt = txt + "<td>&nbsp</td>";
			}
		}	
		txt = txt + "</table>";
		document.getElementById('courses').innerHTML = txt;		
	}
}

function getXMLHttpObject() {
	if(window.XMLHttpRequest) {
		// IE7+, Firefox, Chrome, Safari, Opera
		return new XMLHttpRequest();
	}
	else {
		// IE5, IE6
		return new ActiveObject("Microsoft.XMLHTTP");
	}
	return null;
}
