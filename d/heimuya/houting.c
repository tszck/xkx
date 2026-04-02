// Room: /d/heimuya/houting.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void init();
int do_move(string);
void create()
{
	set("short", "成德殿後廳");
	set("long", @LONG
這裏是日月神教的後廳。看上去滿是灰塵，但廳中石臺面的中間有
一個瓷碗 (wan)，似乎有古怪。
LONG    );
	set("exits", ([
		"east" : __DIR__"house1",
		"west" : __DIR__"restroom",
		"south":__DIR__"chengdedian",
	]));
	set("objects" , ([
		__DIR__"npc/zish" : 4,
	]));
	set("item_desc", ([
		"wan" : "這是一個自漢代流傳下的古董，很別緻。\n",
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 100);
	setup();
}
void init()
{
	add_action("do_circle", "circle");
}

int do_circle(string arg)
{

	object me = this_player();
	object room;

	if ((arg != "wan") || !arg)
		return notify_fail("你要旋什麼？\n");
	if((int)me->query("str") < 12)
		return notify_fail("你臂力連旋不開什麼！\n");
	if(!( room = find_object(__DIR__"didao1")) )
		room = load_object(__DIR__"didao1");
	if(!objectp(room))  return notify_fail("ERROR:not found 'didao1.c' \n");
	if (!query("exits/down"))
	{
		set("exits/down", __DIR__"didao1");
		message_vision("$N將碗旋開，見側牆打開露，出一個黑幽幽的洞口.\n",me);		    
		room->set("exits/out", __DIR__"houting");
		return notify_fail("一定要抓緊時間，走後將它關上。\n");
	}
	if(!( room = find_object(__DIR__"didao1")) )
		room = load_object(__DIR__"didao1");
	if(!objectp(room)) return notify_fail("ERROR:not found 'didao1.c' \n");
	if (!query("exits/down"))
	{
		set("exits/down", __DIR__"didao1");
		message_vision("$N旋動了碗，只見側牆打開，露出一個黑幽幽的洞口。\n",me);
		room->set("exits/out", __DIR__"houting");
		message("vision", "外面傳來一陣搬動碗的聲音，一束光線射了進來。\n", room);
	}
	else
	{
		delete("exits/down");
		message_vision("很快碗又搬回了原位。側牆上的洞口又被封住了。\n",me);
		room->delete("exits/out");
		message("vision", "外面傳來一陣搬動碗的聲音，洞口被封住了。\n", room);
	}
	return 1;
}