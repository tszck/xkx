//Room: /d/dali/tusihouting.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","後廳");
	set("long",@LONG
議事廳後是後廳，是一樓一底的中式建築。屋角雕刻細密，紋飾
精美，各種圖案和禽獸花木的雕刻，栩栩如生，紋路新穎。這是雲南
十八座土司府中保留最好的一座。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"tusimentang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41000);
	set("coor/y", -71000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}