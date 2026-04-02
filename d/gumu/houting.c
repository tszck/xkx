// Room: /d/gumu/houting.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "後廳");
	set("long", @LONG
廳上也是空蕩蕩的沒什麼擺設，正前方寫着一行大字（zi），東西
兩壁都掛着一幅畫。西首 (westpic)的畫像是兩個女郎，正是古墓派的
師尊林朝英和師祖婆婆的肖像，東側 (eastpic)畫像中卻是一個道士。 
    西面可以看到有一扇暗門(door)。
LONG	);

	set("exits", ([
		"east"  : __DIR__"mudao18",
//		"west"  : __DIR__"mudao06",
		"north" : __DIR__"mudao07",
		"south" : __DIR__"mudao19",
	]));
	set("count", 1);
	set("item_desc", ([
		"door" : "一扇厚重的石門，光溜溜的全沒有把手。你認真看了看，發現門邊的石壁上似乎有什麼按鈕(niu)可以開門。\n",
		"westpic" : HIM"畫中兩個姑娘，一個二十五六歲，正在對鏡梳妝，畫中鏡裏映出女郎容貌極美，秀眉入鬢，眼角卻隱隱帶着一層殺氣，正是古墓派師尊林朝英。另一個是十五六歲的丫鬟，手持面盆，在旁伺候，憨態可掬，滿臉稚氣，後來便成了小龍女
的師傅。\n"NOR,
		"eastpic" : HIC"像中道人身材甚高，腰懸長劍，右手食指指着東北角，只是背脊向外，面貌卻看不見。\n"NOR,
		"zi" : HIR"\t入我古墓，先唾重陽，欲成神功，拜我祖師。\n"NOR,
	]));
	set("coor/x", -3180);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
}

void init()
{ 
	add_action("do_ketou", "ketou"); 
	add_action("do_tuo", "tuo");
	add_action("do_an", "press");
	add_action("do_an", "an");
}
 
int do_ketou(string arg)
{
	mapping fam;
	object me = this_player();

	if ((!arg) || (arg != "westpic")) return 0;
		message_vision("$N向西跪倒，雙膝及地，恭恭敬敬向祖師婆婆的畫像磕了一個響頭。\n", me);
	me->add_temp("marks/ketou", 1);
	me->receive_damage("qi", 5);
	if(me->query_temp("marks/tuo") == 2 &&
		me->query_temp("marks/ketou") == 4 &&
		(!(fam = me->query("family")) ||
		fam["family_name"] != "古墓派") &&
		me->query("combat_exp") < 10000)
	{
		me->set("family_name", "古墓派");
		me->set("title", HIW"古墓傳人"NOR);
		me->create_family("古墓派", 5, "傳人");
		me->set("class","swordsman");
		write(HIR"恭喜你自願成爲一名古墓弟子。\n"NOR);
		me->delete_temp("marks/tuo");
		me->delete_temp("marks/ketou");
		return 1;
	}
	if (me->query_temp("marks/ketou") == 15 )
	{
		me->delete_temp("marks/ketou");
		if (query("count") == 0)
			return notify_fail("地上露出一方小孔，但裏面空空如也，想必有人先你下手了。 \n");
		message_vision(HIY "$N面前的石地突然下沉，露出一把金鑰匙，$N把它撿了起來。\n"NOR, me);
		set("count", 0);
		new(__DIR__"obj/goldkey")->move(me);
	}
	return 1;
}

int do_tuo(string arg)
{
	object me = this_player();

	me->receive_damage("qi", 5);
	if (me->query_temp("marks/tuo") == 2)
		return notify_fail("你唾夠了沒有？\n");
	if ( arg=="eastpic")
	{
		message_vision("$N朝王重陽的畫像狠狠唾了一口。\n", me);
		me->add_temp("marks/tuo", 1);
		return 1;
	}
	return notify_fail("你不要隨便亂唾口水啊！\n");
}

int do_an(string arg)
{
	object room, me = this_player();

	if( !arg || arg != "niu" )
	{
		message_vision("你在石壁上亂按一氣，除了一手灰，啥也沒摸着。\n", me);
		return 1;
	}
	if( query("exits/west"))
	{
		return notify_fail("石門已經是開着的，你還按個啥？\n");
	}
	if( me->query_skill("yunv-xinfa", 1) > 10)
	{
		message_vision("$N站在石門前，也不知在哪裏按了一下，石門吱吱響着，緩緩打開了。\n", me);
		if( !(room = find_object(__DIR__"mudao06")) )
			room = load_object(__DIR__"mudao06");
		set("exits/west", __DIR__"mudao06");
		room->set("exits/east", __DIR__"houting");
		tell_room(room,"只聽得石門在吱吱聲中被緩緩打開。\n");
		remove_call_out("close");
		call_out("close", 5, me);
	}
	else
		message_vision("$N試着在石壁上按來按去，可是石門紋絲不動，只得罷了。\n", me);
	return 1;
}

void close(object me)
{
	object room;

	tell_room(this_object(), "石門緩緩地關上，恢復了原狀。\n");
	delete("exits/west");
	if( !(room = find_object(__DIR__"mudao06")) )
		room = load_object(__DIR__"mudao06");
	room->delete("exits/east");
	tell_room(room,"東牆的暗門緩緩地關上了。\n");
}
