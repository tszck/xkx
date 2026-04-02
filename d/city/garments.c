// Room: /city/garments.c

inherit ROOM;

void create()
{
	set("short", "成衣店");
	set("long", @LONG
這裏是揚州名媛貴婦常到之處，現在也擠得悽悽慘慘，脂粉橫飛。
因爲這裏賣的時尚，一直是她們最熱衷的裝扮。店主是個很可人的小女
孩，你認真一看，頓時發現滿個店堂裏的女人加在一起，還不如她靚麗。
    店門口橫橫歪歪地寫着幾個大字(zi)。想來出自小寶手筆。
LONG );
	set("item_desc", ([
		"zi": "list 看，\"buy\" 買。\n",
	]));
	set("exits", ([
		"northeast" : __DIR__"caohecexiang",
	]));
	set("objects", ([
		__DIR__"npc/zeng": 1,
	]));
	set("coor/x", -31);
	set("coor/y", -21);
	set("coor/z", 0);
	set("no_fight", 1);
	setup();
	replace_program(ROOM);
}
