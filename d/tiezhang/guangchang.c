// Room: /d/tiezhang/guangchang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "廣場");
	set("long", @LONG
山路行到這裏，忽然變得開闊，你眼前出現了一片很大的廣場。一
些鐵掌幫的弟子來回穿梭於其間，顯得很忙碌。在廣場的周圍有很多巖
石建的房子。正面的這間尤其顯得高大雄偉。左面的房子中不時的湧出
陣陣熱氣，其間還加雜着鼓風的聲音。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"west"    : __DIR__"lgfang",
		"east"    : __DIR__"guajia",
		"south"   : __DIR__"shanlu2",
		"northup" : __DIR__"wztang",
	]));
	set("objects", ([ /* sizeof() == 3 */
		__DIR__"npc/huiyi" : 1,
		__DIR__"npc/heiyi" : 2,
	]));
	set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2040);
	set("coor/y", -1970);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
	"/clone/board/tiezhang_b"->foo();
}