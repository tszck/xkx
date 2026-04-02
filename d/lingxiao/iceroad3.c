// Room: /d/lingxiao/iceroad3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","冰道");
	set("long",@LONG
這條冰道的兩邊都很安靜。西邊是冰車，東邊是凌霄城的監獄。北
邊過去，就是凌霄城的根本之地----雪山派的總堂凌霄殿了，這裏防守
緊密，四處都是凌霄弟子。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"iceroad2",
		"north" : __DIR__"meiroad1",
		"west"  : __DIR__"car",
		"east"  : __DIR__"jianyuting",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 2,
	]));
	set("coor/x", -31000);
	set("coor/y", -8900);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}
