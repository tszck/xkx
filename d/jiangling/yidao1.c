//Edited by fandog, 02/15/2000

inherit ROOM;
void create()
{
	set("short", "驛道");
	set("long", @LONG
你走在一條塵土飛揚的大驛道上。四周人來人往。挑擔子的行商，
趕着大車的馬伕，出門遠遊的書生，熙熙攘攘，非常熱鬧。不時還有兩
三騎快馬從身邊飛馳而過，揚起一路塵埃。馬上的人個個身着勁裝，衣
甲鮮明，有的還隨身佩帶着刀劍。看來都是些習武的江湖人。道路兩旁
是整整齊齊的楊樹林。你側耳細聽，隱約可以感覺大江的奔流。北邊有
座木橋。
LONG );
	set("exits", ([
		"south" : __DIR__"yidao",
		"north" : __DIR__"dangyangqiao",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}