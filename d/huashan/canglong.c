// canglong.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "蒼龍嶺");
	set("long", @LONG
華山五峯中最驚險的是北峯，北峯之上最陡峭的則是蒼龍嶺。此嶺
高約百米，寬僅一米，而登山之路則在其山脊之上，兩側脊坡光滑挺拔，
其下懸崖深邃，雲濤隱伏，嶺體蜿蜒逶迤，體青背黑，如蒼龍騰空，故
有是名。嶺側有一石碑(shibei)。
	從這裏往東是下山的路，再往南是上其它四峯的路，西面是華山極
險處之一，叫做“捨身崖”。
LONG );
	set("exits", ([ /* sizeof() == 3 */
		"westup"   : __DIR__"sheshen",
		"northup"  : __DIR__"yuntai",
		"eastdown" : __DIR__"shangtianti",
	]));
	set("item_desc", ([
		"shibei" :
"石碑刻着幾個大字：「韓退之投書處」，據説當年韓愈爬上此嶺之後，\n
再也不敢下來，自以為要死在山上，就在山上寫信投下來，和家人訣別。\n
後來還是華陰縣的縣官派人上山拿繩子把他捆着吊下來的。\n"
]) ) ;
	set("objects", ([
		__DIR__"npc/liang-fa" : 1,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -880);
	set("coor/y", 210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
 
