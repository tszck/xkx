// Room: /d/lingxiao/walle3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "城頭");
	set("long", @LONG
遠山渺渺，冷風蕭蕭。試拂鐵衣，只見衣色似雪，在這凌霄之處，
惟有雨雪連綿，以陪弋人。大漠蒼蒼，遠空一鷹高翔，振翅直飛九霄，
忽而又直衝而下，翱翔九天，瞬間無蹤，只有白雲千載，仍在這座孤城
上悠悠飄蕩。
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"west" : __DIR__"walle2",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -30970);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}

