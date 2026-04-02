// Room: /d/tiezhang/pingtai.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
string look_ditu();
void create()
{
	set("short", BLU"山間平臺"NOR);
	set("long", @LONG
這裏是山間的一塊平地。山勢在這裏開始分支，矗立在面前的有五
座高聳入雲的山峯，行似人的五指，“鐵掌山”之名由此而得。五峯雖
同處此山，但拇指峯之雄偉，食指峯之險峻，中指峯之高聳，無名峯之奇
麗，小指峯之秀美，則各有特色，各擅勝場。在平臺一側的大石上，刻着
一副地圖(ditu)。
LONG	);
	set("item_desc", ([ 
		"ditu" : (: look_ditu :),
	]));
	set("exits", ([ 
		"westup"    : __DIR__"shanlu5",
		"northeast" : __DIR__"shangu1",
		"eastup"    : __DIR__"sslu1",
		"southdown" : __DIR__"shanlu4",
		"northwest" : __DIR__"hclu1",
		"northup"   : __DIR__"shanlu6",
	]));
	set("objects", ([ 
		__DIR__"npc/huiyi" : 3,
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", -1910);
	set("coor/z", 50);
	setup();
}

string look_ditu()
{
	return
	"\n"
	"############################\n"
	"#          中指峯          #\n"
	"#            ||            #\n"
	"#    無名峯  ||  食指峯    #\n"
	"#         \\ || //         #\n"
	"#          \\||//          #\n"
	"# 小指峯====平臺====拇指峯 #\n"
	"############################\n";
	"\n";
}
