/* Generated by re2c */
#line 1 "unicode_group_So.x--encoding-policy(substitute).re"
#include <stdio.h>
#include "utf16.h"
#define YYCTYPE unsigned short
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
So:
	
#line 13 "unicode_group_So.x--encoding-policy(substitute).c"
{
	YYCTYPE yych;
	yych = *YYCURSOR;
	if (yych <= 0x21D3) {
		if (yych <= 0x109F) {
			if (yych <= 0x0BF8) {
				if (yych <= 0x060F) {
					if (yych <= 0x00AF) {
						if (yych <= 0x00A8) {
							if (yych <= 0x00A5) goto yy2;
							if (yych <= 0x00A7) goto yy4;
						} else {
							if (yych <= 0x00A9) goto yy4;
							if (yych == 0x00AE) goto yy4;
						}
					} else {
						if (yych <= 0x00B6) {
							if (yych <= 0x00B0) goto yy4;
							if (yych >= 0x00B6) goto yy4;
						} else {
							if (yych == 0x0482) goto yy4;
							if (yych >= 0x060E) goto yy4;
						}
					}
				} else {
					if (yych <= 0x07F5) {
						if (yych <= 0x06E8) {
							if (yych == 0x06DE) goto yy4;
						} else {
							if (yych <= 0x06E9) goto yy4;
							if (yych <= 0x06FC) goto yy2;
							if (yych <= 0x06FE) goto yy4;
						}
					} else {
						if (yych <= 0x09FA) {
							if (yych <= 0x07F6) goto yy4;
							if (yych >= 0x09FA) goto yy4;
						} else {
							if (yych == 0x0B70) goto yy4;
							if (yych >= 0x0BF3) goto yy4;
						}
					}
				}
			} else {
				if (yych <= 0x0F34) {
					if (yych <= 0x0F00) {
						if (yych <= 0x0C7E) {
							if (yych == 0x0BFA) goto yy4;
						} else {
							if (yych <= 0x0C7F) goto yy4;
							if (yych == 0x0D79) goto yy4;
						}
					} else {
						if (yych <= 0x0F17) {
							if (yych <= 0x0F03) goto yy4;
							if (yych >= 0x0F13) goto yy4;
						} else {
							if (yych <= 0x0F19) goto yy2;
							if (yych <= 0x0F1F) goto yy4;
							if (yych >= 0x0F34) goto yy4;
						}
					}
				} else {
					if (yych <= 0x0FC6) {
						if (yych <= 0x0F37) {
							if (yych == 0x0F36) goto yy4;
						} else {
							if (yych <= 0x0F38) goto yy4;
							if (yych <= 0x0FBD) goto yy2;
							if (yych <= 0x0FC5) goto yy4;
						}
					} else {
						if (yych <= 0x0FCF) {
							if (yych != 0x0FCD) goto yy4;
						} else {
							if (yych <= 0x0FD4) goto yy2;
							if (yych <= 0x0FD8) goto yy4;
							if (yych >= 0x109E) goto yy4;
						}
					}
				}
			}
		} else {
			if (yych <= 0x2127) {
				if (yych <= 0x2101) {
					if (yych <= 0x19DD) {
						if (yych <= 0x138F) {
							if (yych == 0x1360) goto yy4;
						} else {
							if (yych <= 0x1399) goto yy4;
							if (yych == 0x1940) goto yy4;
						}
					} else {
						if (yych <= 0x1B6A) {
							if (yych <= 0x19FF) goto yy4;
							if (yych >= 0x1B61) goto yy4;
						} else {
							if (yych <= 0x1B73) goto yy2;
							if (yych <= 0x1B7C) goto yy4;
							if (yych >= 0x2100) goto yy4;
						}
					}
				} else {
					if (yych <= 0x2115) {
						if (yych <= 0x2107) {
							if (yych <= 0x2102) goto yy2;
							if (yych <= 0x2106) goto yy4;
						} else {
							if (yych <= 0x2109) goto yy4;
							if (yych == 0x2114) goto yy4;
						}
					} else {
						if (yych <= 0x2123) {
							if (yych <= 0x2117) goto yy4;
							if (yych >= 0x211E) goto yy4;
						} else {
							if (yych == 0x2125) goto yy4;
							if (yych >= 0x2127) goto yy4;
						}
					}
				}
			} else {
				if (yych <= 0x2199) {
					if (yych <= 0x2149) {
						if (yych <= 0x212D) {
							if (yych == 0x2129) goto yy4;
						} else {
							if (yych <= 0x212E) goto yy4;
							if (yych <= 0x2139) goto yy2;
							if (yych <= 0x213B) goto yy4;
						}
					} else {
						if (yych <= 0x214D) {
							if (yych != 0x214B) goto yy4;
						} else {
							if (yych == 0x214F) goto yy4;
							if (yych >= 0x2195) goto yy4;
						}
					}
				} else {
					if (yych <= 0x21A6) {
						if (yych <= 0x21A0) {
							if (yych <= 0x219B) goto yy2;
							if (yych <= 0x219F) goto yy4;
						} else {
							if (yych == 0x21A3) goto yy2;
							if (yych <= 0x21A5) goto yy4;
						}
					} else {
						if (yych <= 0x21CD) {
							if (yych != 0x21AE) goto yy4;
						} else {
							if (yych <= 0x21CF) goto yy2;
							if (yych != 0x21D2) goto yy4;
						}
					}
				}
			}
		}
	} else {
		if (yych <= 0x3004) {
			if (yych <= 0x25F7) {
				if (yych <= 0x23DB) {
					if (yych <= 0x2321) {
						if (yych <= 0x22FF) {
							if (yych <= 0x21D4) goto yy2;
							if (yych <= 0x21F3) goto yy4;
						} else {
							if (yych <= 0x2307) goto yy4;
							if (yych <= 0x230B) goto yy2;
							if (yych <= 0x231F) goto yy4;
						}
					} else {
						if (yych <= 0x237B) {
							if (yych <= 0x2328) goto yy4;
							if (yych >= 0x232B) goto yy4;
						} else {
							if (yych <= 0x237C) goto yy2;
							if (yych <= 0x239A) goto yy4;
							if (yych >= 0x23B4) goto yy4;
						}
					}
				} else {
					if (yych <= 0x249B) {
						if (yych <= 0x23FF) {
							if (yych <= 0x23E1) goto yy2;
							if (yych <= 0x23F3) goto yy4;
						} else {
							if (yych <= 0x2426) goto yy4;
							if (yych <= 0x243F) goto yy2;
							if (yych <= 0x244A) goto yy4;
						}
					} else {
						if (yych <= 0x25B6) {
							if (yych <= 0x24E9) goto yy4;
							if (yych >= 0x2500) goto yy4;
						} else {
							if (yych <= 0x25B7) goto yy2;
							if (yych != 0x25C1) goto yy4;
						}
					}
				}
			} else {
				if (yych <= 0x2B46) {
					if (yych <= 0x2793) {
						if (yych <= 0x266F) {
							if (yych <= 0x25FF) goto yy2;
							if (yych <= 0x266E) goto yy4;
						} else {
							if (yych == 0x2700) goto yy2;
							if (yych <= 0x2767) goto yy4;
						}
					} else {
						if (yych <= 0x28FF) {
							if (yych <= 0x27BF) goto yy4;
							if (yych >= 0x2800) goto yy4;
						} else {
							if (yych <= 0x2AFF) goto yy2;
							if (yych <= 0x2B2F) goto yy4;
							if (yych >= 0x2B45) goto yy4;
						}
					}
				} else {
					if (yych <= 0x2E9A) {
						if (yych <= 0x2CE4) {
							if (yych <= 0x2B4F) goto yy2;
							if (yych <= 0x2B59) goto yy4;
						} else {
							if (yych <= 0x2CEA) goto yy4;
							if (yych <= 0x2E7F) goto yy2;
							if (yych <= 0x2E99) goto yy4;
						}
					} else {
						if (yych <= 0x2FD5) {
							if (yych <= 0x2EF3) goto yy4;
							if (yych >= 0x2F00) goto yy4;
						} else {
							if (yych <= 0x2FEF) goto yy2;
							if (yych <= 0x2FFB) goto yy4;
							if (yych >= 0x3004) goto yy4;
						}
					}
				}
			}
		} else {
			if (yych <= 0x4DFF) {
				if (yych <= 0x31E3) {
					if (yych <= 0x303D) {
						if (yych <= 0x301F) {
							if (yych <= 0x3011) goto yy2;
							if (yych <= 0x3013) goto yy4;
						} else {
							if (yych <= 0x3020) goto yy4;
							if (yych <= 0x3035) goto yy2;
							if (yych <= 0x3037) goto yy4;
						}
					} else {
						if (yych <= 0x3191) {
							if (yych <= 0x303F) goto yy4;
							if (yych >= 0x3190) goto yy4;
						} else {
							if (yych <= 0x3195) goto yy2;
							if (yych <= 0x319F) goto yy4;
							if (yych >= 0x31C0) goto yy4;
						}
					}
				} else {
					if (yych <= 0x3289) {
						if (yych <= 0x3229) {
							if (yych <= 0x31FF) goto yy2;
							if (yych <= 0x321E) goto yy4;
						} else {
							if (yych <= 0x3250) goto yy4;
							if (yych <= 0x325F) goto yy2;
							if (yych <= 0x327F) goto yy4;
						}
					} else {
						if (yych <= 0x32FE) {
							if (yych <= 0x32B0) goto yy4;
							if (yych >= 0x32C0) goto yy4;
						} else {
							if (yych <= 0x32FF) goto yy2;
							if (yych <= 0x33FF) goto yy4;
							if (yych >= 0x4DC0) goto yy4;
						}
					}
				}
			} else {
				if (yych <= 0xD834) {
					if (yych <= 0xA838) {
						if (yych <= 0xA827) {
							if (yych <= 0xA48F) goto yy2;
							if (yych <= 0xA4C6) goto yy4;
						} else {
							if (yych <= 0xA82B) goto yy4;
							if (yych <= 0xA835) goto yy2;
							if (yych <= 0xA837) goto yy4;
						}
					} else {
						if (yych <= 0xAA79) {
							if (yych <= 0xA839) goto yy4;
							if (yych >= 0xAA77) goto yy4;
						} else {
							if (yych == 0xD800) goto yy6;
							if (yych >= 0xD834) goto yy7;
						}
					}
				} else {
					if (yych <= 0xFFE4) {
						if (yych <= 0xD83D) {
							if (yych <= 0xD83B) goto yy2;
							if (yych <= 0xD83C) goto yy8;
							goto yy9;
						} else {
							if (yych == 0xFDFD) goto yy4;
							if (yych >= 0xFFE4) goto yy4;
						}
					} else {
						if (yych <= 0xFFEC) {
							if (yych == 0xFFE8) goto yy4;
						} else {
							if (yych <= 0xFFEE) goto yy4;
							if (yych <= 0xFFFB) goto yy2;
							if (yych <= 0xFFFD) goto yy4;
						}
					}
				}
			}
		}
	}
yy2:
	++YYCURSOR;
yy3:
#line 13 "unicode_group_So.x--encoding-policy(substitute).re"
	{ return YYCURSOR == limit; }
#line 349 "unicode_group_So.x--encoding-policy(substitute).c"
yy4:
	++YYCURSOR;
#line 12 "unicode_group_So.x--encoding-policy(substitute).re"
	{ goto So; }
#line 354 "unicode_group_So.x--encoding-policy(substitute).c"
yy6:
	yych = *++YYCURSOR;
	if (yych <= 0xDD78) {
		if (yych <= 0xDD02) {
			if (yych <= 0xDD01) goto yy3;
			goto yy4;
		} else {
			if (yych <= 0xDD36) goto yy3;
			if (yych <= 0xDD3F) goto yy4;
			goto yy3;
		}
	} else {
		if (yych <= 0xDD9B) {
			if (yych <= 0xDD89) goto yy4;
			if (yych <= 0xDD8F) goto yy3;
			goto yy4;
		} else {
			if (yych <= 0xDDCF) goto yy3;
			if (yych <= 0xDDFC) goto yy4;
			goto yy3;
		}
	}
yy7:
	yych = *++YYCURSOR;
	if (yych <= 0xDD84) {
		if (yych <= 0xDD28) {
			if (yych <= 0xDCF5) {
				if (yych <= 0xDBFF) goto yy3;
				goto yy4;
			} else {
				if (yych <= 0xDCFF) goto yy3;
				if (yych <= 0xDD26) goto yy4;
				goto yy3;
			}
		} else {
			if (yych <= 0xDD69) {
				if (yych <= 0xDD64) goto yy4;
				goto yy3;
			} else {
				if (yych <= 0xDD6C) goto yy4;
				if (yych <= 0xDD82) goto yy3;
				goto yy4;
			}
		}
	} else {
		if (yych <= 0xDDFF) {
			if (yych <= 0xDDA9) {
				if (yych <= 0xDD8B) goto yy3;
				goto yy4;
			} else {
				if (yych <= 0xDDAD) goto yy3;
				if (yych <= 0xDDDD) goto yy4;
				goto yy3;
			}
		} else {
			if (yych <= 0xDE45) {
				if (yych <= 0xDE41) goto yy4;
				if (yych <= 0xDE44) goto yy3;
				goto yy4;
			} else {
				if (yych <= 0xDEFF) goto yy3;
				if (yych <= 0xDF56) goto yy4;
				goto yy3;
			}
		}
	}
yy8:
	yych = *++YYCURSOR;
	if (yych <= 0xDE02) {
		if (yych <= 0xDCCF) {
			if (yych <= 0xDC9F) {
				if (yych <= 0xDC2B) {
					if (yych <= 0xDBFF) goto yy3;
					goto yy4;
				} else {
					if (yych <= 0xDC2F) goto yy3;
					if (yych <= 0xDC93) goto yy4;
					goto yy3;
				}
			} else {
				if (yych <= 0xDCB0) {
					if (yych <= 0xDCAE) goto yy4;
					goto yy3;
				} else {
					if (yych <= 0xDCBE) goto yy4;
					if (yych <= 0xDCC0) goto yy3;
					goto yy4;
				}
			}
		} else {
			if (yych <= 0xDD2F) {
				if (yych <= 0xDCDF) {
					if (yych <= 0xDCD0) goto yy3;
					goto yy4;
				} else {
					if (yych <= 0xDD0F) goto yy3;
					if (yych <= 0xDD2E) goto yy4;
					goto yy3;
				}
			} else {
				if (yych <= 0xDD6F) {
					if (yych <= 0xDD69) goto yy4;
					goto yy3;
				} else {
					if (yych <= 0xDD9A) goto yy4;
					if (yych <= 0xDDE5) goto yy3;
					goto yy4;
				}
			}
		}
	} else {
		if (yych <= 0xDF35) {
			if (yych <= 0xDE4F) {
				if (yych <= 0xDE3A) {
					if (yych <= 0xDE0F) goto yy3;
					goto yy4;
				} else {
					if (yych <= 0xDE3F) goto yy3;
					if (yych <= 0xDE48) goto yy4;
					goto yy3;
				}
			} else {
				if (yych <= 0xDEFF) {
					if (yych <= 0xDE51) goto yy4;
					goto yy3;
				} else {
					if (yych <= 0xDF20) goto yy4;
					if (yych <= 0xDF2F) goto yy3;
					goto yy4;
				}
			}
		} else {
			if (yych <= 0xDF9F) {
				if (yych <= 0xDF7C) {
					if (yych <= 0xDF36) goto yy3;
					goto yy4;
				} else {
					if (yych <= 0xDF7F) goto yy3;
					if (yych <= 0xDF93) goto yy4;
					goto yy3;
				}
			} else {
				if (yych <= 0xDFCA) {
					if (yych == 0xDFC5) goto yy3;
					goto yy4;
				} else {
					if (yych <= 0xDFDF) goto yy3;
					if (yych <= 0xDFF0) goto yy4;
					goto yy3;
				}
			}
		}
	}
yy9:
	yych = *++YYCURSOR;
	if (yych <= 0xDE17) {
		if (yych <= 0xDD3D) {
			if (yych <= 0xDC41) {
				if (yych <= 0xDC3E) {
					if (yych <= 0xDBFF) goto yy3;
					goto yy4;
				} else {
					if (yych == 0xDC40) goto yy4;
					goto yy3;
				}
			} else {
				if (yych <= 0xDCF8) {
					if (yych <= 0xDCF7) goto yy4;
					goto yy3;
				} else {
					if (yych <= 0xDCFC) goto yy4;
					if (yych <= 0xDCFF) goto yy3;
					goto yy4;
				}
			}
		} else {
			if (yych <= 0xDE00) {
				if (yych <= 0xDD67) {
					if (yych <= 0xDD4F) goto yy3;
					goto yy4;
				} else {
					if (yych <= 0xDDFA) goto yy3;
					if (yych <= 0xDDFF) goto yy4;
					goto yy3;
				}
			} else {
				if (yych <= 0xDE14) {
					if (yych == 0xDE11) goto yy3;
					goto yy4;
				} else {
					if (yych == 0xDE16) goto yy4;
					goto yy3;
				}
			}
		}
	} else {
		if (yych <= 0xDE2D) {
			if (yych <= 0xDE1E) {
				if (yych <= 0xDE19) {
					if (yych <= 0xDE18) goto yy4;
					goto yy3;
				} else {
					if (yych == 0xDE1B) goto yy3;
					goto yy4;
				}
			} else {
				if (yych <= 0xDE27) {
					if (yych <= 0xDE1F) goto yy3;
					if (yych <= 0xDE25) goto yy4;
					goto yy3;
				} else {
					if (yych == 0xDE2C) goto yy3;
					goto yy4;
				}
			}
		} else {
			if (yych <= 0xDE44) {
				if (yych <= 0xDE33) {
					if (yych <= 0xDE2F) goto yy3;
					goto yy4;
				} else {
					if (yych <= 0xDE34) goto yy3;
					if (yych <= 0xDE40) goto yy4;
					goto yy3;
				}
			} else {
				if (yych <= 0xDEC5) {
					if (yych <= 0xDE4F) goto yy4;
					if (yych <= 0xDE7F) goto yy3;
					goto yy4;
				} else {
					if (yych <= 0xDEFF) goto yy3;
					if (yych <= 0xDF73) goto yy4;
					goto yy3;
				}
			}
		}
	}
}
#line 14 "unicode_group_So.x--encoding-policy(substitute).re"

}
static const unsigned int chars_So [] = {0xa6,0xa7,  0xa9,0xa9,  0xae,0xae,  0xb0,0xb0,  0xb6,0xb6,  0x482,0x482,  0x60e,0x60f,  0x6de,0x6de,  0x6e9,0x6e9,  0x6fd,0x6fe,  0x7f6,0x7f6,  0x9fa,0x9fa,  0xb70,0xb70,  0xbf3,0xbf8,  0xbfa,0xbfa,  0xc7f,0xc7f,  0xd79,0xd79,  0xf01,0xf03,  0xf13,0xf17,  0xf1a,0xf1f,  0xf34,0xf34,  0xf36,0xf36,  0xf38,0xf38,  0xfbe,0xfc5,  0xfc7,0xfcc,  0xfce,0xfcf,  0xfd5,0xfd8,  0x109e,0x109f,  0x1360,0x1360,  0x1390,0x1399,  0x1940,0x1940,  0x19de,0x19ff,  0x1b61,0x1b6a,  0x1b74,0x1b7c,  0x2100,0x2101,  0x2103,0x2106,  0x2108,0x2109,  0x2114,0x2114,  0x2116,0x2117,  0x211e,0x2123,  0x2125,0x2125,  0x2127,0x2127,  0x2129,0x2129,  0x212e,0x212e,  0x213a,0x213b,  0x214a,0x214a,  0x214c,0x214d,  0x214f,0x214f,  0x2195,0x2199,  0x219c,0x219f,  0x21a1,0x21a2,  0x21a4,0x21a5,  0x21a7,0x21ad,  0x21af,0x21cd,  0x21d0,0x21d1,  0x21d3,0x21d3,  0x21d5,0x21f3,  0x2300,0x2307,  0x230c,0x231f,  0x2322,0x2328,  0x232b,0x237b,  0x237d,0x239a,  0x23b4,0x23db,  0x23e2,0x23f3,  0x2400,0x2426,  0x2440,0x244a,  0x249c,0x24e9,  0x2500,0x25b6,  0x25b8,0x25c0,  0x25c2,0x25f7,  0x2600,0x266e,  0x2670,0x26ff,  0x2701,0x2767,  0x2794,0x27bf,  0x2800,0x28ff,  0x2b00,0x2b2f,  0x2b45,0x2b46,  0x2b50,0x2b59,  0x2ce5,0x2cea,  0x2e80,0x2e99,  0x2e9b,0x2ef3,  0x2f00,0x2fd5,  0x2ff0,0x2ffb,  0x3004,0x3004,  0x3012,0x3013,  0x3020,0x3020,  0x3036,0x3037,  0x303e,0x303f,  0x3190,0x3191,  0x3196,0x319f,  0x31c0,0x31e3,  0x3200,0x321e,  0x322a,0x3250,  0x3260,0x327f,  0x328a,0x32b0,  0x32c0,0x32fe,  0x3300,0x33ff,  0x4dc0,0x4dff,  0xa490,0xa4c6,  0xa828,0xa82b,  0xa836,0xa837,  0xa839,0xa839,  0xaa77,0xaa79,  0xfdfd,0xfdfd,  0xffe4,0xffe4,  0xffe8,0xffe8,  0xffed,0xffee,  0xfffc,0xfffd,  0x10102,0x10102,  0x10137,0x1013f,  0x10179,0x10189,  0x10190,0x1019b,  0x101d0,0x101fc,  0x1d000,0x1d0f5,  0x1d100,0x1d126,  0x1d129,0x1d164,  0x1d16a,0x1d16c,  0x1d183,0x1d184,  0x1d18c,0x1d1a9,  0x1d1ae,0x1d1dd,  0x1d200,0x1d241,  0x1d245,0x1d245,  0x1d300,0x1d356,  0x1f000,0x1f02b,  0x1f030,0x1f093,  0x1f0a0,0x1f0ae,  0x1f0b1,0x1f0be,  0x1f0c1,0x1f0cf,  0x1f0d1,0x1f0df,  0x1f110,0x1f12e,  0x1f130,0x1f169,  0x1f170,0x1f19a,  0x1f1e6,0x1f202,  0x1f210,0x1f23a,  0x1f240,0x1f248,  0x1f250,0x1f251,  0x1f300,0x1f320,  0x1f330,0x1f335,  0x1f337,0x1f37c,  0x1f380,0x1f393,  0x1f3a0,0x1f3c4,  0x1f3c6,0x1f3ca,  0x1f3e0,0x1f3f0,  0x1f400,0x1f43e,  0x1f440,0x1f440,  0x1f442,0x1f4f7,  0x1f4f9,0x1f4fc,  0x1f500,0x1f53d,  0x1f550,0x1f567,  0x1f5fb,0x1f5ff,  0x1f601,0x1f610,  0x1f612,0x1f614,  0x1f616,0x1f616,  0x1f618,0x1f618,  0x1f61a,0x1f61a,  0x1f61c,0x1f61e,  0x1f620,0x1f625,  0x1f628,0x1f62b,  0x1f62d,0x1f62d,  0x1f630,0x1f633,  0x1f635,0x1f640,  0x1f645,0x1f64f,  0x1f680,0x1f6c5,  0x1f700,0x1f773,  0x0,0x0};
static unsigned int encode_utf16 (const unsigned int * ranges, unsigned int ranges_count, unsigned short * s)
{
	unsigned short * const s_start = s;
	for (unsigned int i = 0; i < ranges_count; i += 2)
		for (unsigned int j = ranges[i]; j <= ranges[i + 1]; ++j)
		{
			if (j <= re2c::utf16::MAX_1WORD_RUNE)
				*s++ = j;
			else
			{
				*s++ = re2c::utf16::lead_surr(j);
				*s++ = re2c::utf16::trail_surr(j);
			}
		}
	return s - s_start;
}

int main ()
{
	YYCTYPE * buffer_So = new YYCTYPE [8798];
	unsigned int buffer_len = encode_utf16 (chars_So, sizeof (chars_So) / sizeof (unsigned int), buffer_So);
	if (!scan (reinterpret_cast<const YYCTYPE *> (buffer_So), reinterpret_cast<const YYCTYPE *> (buffer_So + buffer_len)))
		printf("test 'So' failed\n");
	delete [] buffer_So;
	return 0;
}
