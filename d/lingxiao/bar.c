// Room: /d/lingxiao/.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "石崖客棧");
	set("long", @LONG
這裏是雪山山路上的一間客棧，雖然店面簡單樸實，平日也不可能
有什麼遊客來這雪域遊山玩水，但在這大雪山上，卻也是獨一無二的客
棧。到了這地方，要是不想凍死在這萬裏冰川上，只怕還是得照顧一下
這裏的生意。所以這家店倒也是生意興隆。
LONG );
	set("exits", ([
		"west" : __DIR__"shiya",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
		__DIR__"npc/dizi" : 2,
	]));
	set("coor/x", -30990);
	set("coor/y", -8980);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

