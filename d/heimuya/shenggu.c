// Room: /d/heimuya/shenggu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM; 
void create()
{
	set("short", "聖姑堂");
	set("long",@LONG
這裏便是黑木崖的聖姑所在地“聖姑堂”。堂上五彩雲羅，煞是漂
亮。不過，聖姑對黑木崖俗務久已厭倦，一年之中倒有八九個月不在堂
中。
LONG );
	set("exits", ([
		"east" : __DIR__"chitang",
	]));
	set("objects", ([
//		CLASS_D("heimuya")+"/renyy" : 1,
		__DIR__"npc/shinu" : 2,
	]));       
//	set("no_clean_up", 0);
	set("coor/x", -3050);
	set("coor/y", 3990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}