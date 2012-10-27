{
  "targets": [
	  {
		  "target_name": "csegment",
		  'include_dirs': [ "ICTCLAS" ],
		  'defines': ['OS_LINUX',],
		  'libraries': [
		  		'/data1/www/htdocs/project/ha/node/csegment/ICTCLAS/libICTCLAS50.so',
		  ],
		  "sources": [ "csegment.cc" ],
	  },

  ],
}

