// ROOM liandaoshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "煉刀場");
	set("long", @LONG
這裏是玄兵古洞的煉刀場。四處充滿了金屬的氣味，炙熱的氣浪衝
的人不由打了個趔趄。一個皮膚黝黑的小夥正坐在一塊石頭上休息，手
中一個巨大的錘頭正不停的來回擺動着。看來這小夥快要睡着了。
LONG );
	set("exits", ([
		"south" : "/d/xingxiu/tianroad5",
	]));
	set("objects", ([
		__DIR__"npc/shidao" :1,
	]));
	set("coor/x", -52010);
	set("coor/y", 20150);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
