// Room: /d/lingxiao/didi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "地底");
	set("long", @LONG 
這裏按地勢而言，早已深入地底，是這大雪山的山腹之中了。四周
土地潮濕，充滿了一股濃濃的泥土味。牆上依然插着幾支火把，照得四
周亮堂堂的。一個腰懸利劍，神情警惕的劍士，正守在一扇巨大的石門
（men）旁。
LONG );
	set("exits", ([
		"up" : __DIR__"laolang",
	]));
	set("objects", ([ 
		__DIR__"npc/shi" : 1,
	])); 
	set("item_desc", ([
		"men" : "一扇厚厚的石門,怕有千斤之重，使勁推推（push），不知道會不會開。\n"
	]) );
	set("coor/x", -30990);
	set("coor/y", -8900);
	set("coor/z", 120);
	setup(); 
}

void init()
{
	add_action("do_push", "push");
}
int do_push(string arg)
{
	object me=this_player();

	message_vision("$N氣沉丹田，凝勁於腰，大喝一聲，運勁向石門推去。\n",me);
	if (me->query("max_neili") < 500)
	{
		message_vision("$N累了個半死，石門卻紋絲不動。\n",me);
		return 1;
	}
	message_vision("只聽機關樞紐運做之聲不絕，石門竟緩緩開了。\n",me);
	set("exits/enter",__DIR__"dilao");
	remove_call_out("close");
	call_out("close", 5, this_object());
	return 1;
}
void close_out()
{
	if (query("exits/enter")) delete("exits/enter");
}

void close(object room)
{
	message("vision","裏面有人大喝一聲：小王八蛋，你不進來，就給爺爺滾吧！話音剛落，一陣勁風擊到，石門被砰地一下關了。\n", room);
	room->delete("exits/enter");
}

