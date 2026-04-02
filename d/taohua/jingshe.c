// Room: /d/taohua/jingshe.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;
int do_pai(string arg);

void create()
{
	set("short","精舍");
	set("long",@LONG
這是桃花島主黃藥師的書房，全是以不刨皮的松樹搭成，屋外攀滿
了青藤。即便正當炎夏，一見到這間屋子，都是突感一陣清涼。屋裏滿
是詩經典籍玉器古玩。屋邊擺着一張桌子(zhuozi)。正面的牆壁上掛着
一幅淡墨山水。
LONG
	);
	set("exits",([
		"south" : __DIR__"dating",
	]) );
	set("no_clean_up",0);
	set("item_desc",([
		"table" : "這是一張石桌。\n",
		"zhuozi" : "這是一張石桌。\n",
	]) );
	set("coor/x", 9010);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_pai", "pai");
	add_action("do_pai", "press");
}

void close_door(object room)
{
	message("vision", "卷軸自動拉下來，遮住了入口。\n", room);
	room->delete("exits/enter");
}

int do_pai(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
	if( arg == "table" || arg == "zhuozi")
        {
		write("正面壁上掛着的淡墨山水忽地徐徐升起，露出一個暗間來。\n");
		set("exits/enter", __DIR__"liandanfang");
		remove_call_out("close_door");
		call_out("close_door", 5, this_object());

                return 1;
        }
}