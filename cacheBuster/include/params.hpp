//
//  params.h
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#ifndef params_h
#define params_h

#define DEBUG_INFO 1
#define HIDDEN_DOT 0x2E

static const char EXT_JS[] = ".js";
static const char EXT_CSS[] = ".css";
static const char EXT_HTML[] = ".html";

enum Extension {
	js,
	css,
	html,
	invalid
};

#endif /* params_h */
