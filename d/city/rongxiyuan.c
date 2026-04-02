// Room: /yangzhou/rongxiyuan.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "容膝園");
	set("long", @LONG
在園之東北隅，疊山石一撮，植花木少許。在園之西側，貼牆築半
廊，與半亭連續。於園之西南，橫斷園林，造客齋一間。齋之南，留有
隙地，到也小有天地。整個園地，縱深約三十步，寬僅十步許。身步不
移，全園景物，即可全收眼底。北向有堂屋一間。
LONG );

	set("outdoors", "yangzhouw");
	set("exits", ([
		"south" : __DIR__"hejiajie",
		"north" : __DIR__"tangwu1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}