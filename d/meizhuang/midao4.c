// /d/meizhuang/midao4.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
這是一條在西湖底下的地道。牆壁上點着一盞油燈，發出淡黃色光
芒。光芒照着拐彎處朝東的一間囚室。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"northup"   : __DIR__"midao3",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1450);
	set("coor/z", -150);
	setup();
}
void init()
{
	add_action("do_unlock", "unlock");
}
int do_unlock(string arg)
{
	object ob, jianyu;

	if (query("exits/east"))
		return notify_fail("這扇囚門已經是打開的。\n");
	if (!arg || (arg != "men" && arg != "door"))
		return notify_fail("你要打開什麼？\n");
	if (!(ob = present("gang yaoshi", this_player())))
		return notify_fail("你不會撬鎖。\n");
	if(!( jianyu = find_object(__DIR__"jianyu")) )
		jianyu = load_object(__DIR__"jianyu");
	if(objectp(jianyu))
	{
		set("exits/east", __DIR__"jianyu");
		message_vision("$N把鋼芯鑰匙插入了一個匙孔，轉了幾轉，向內推動。\n只聽得一陣生澀的響動，$N伸手把囚門拉開。\n", this_player());
		jianyu->set("exits/west", __FILE__);
                message("vision","只聽一陣鑰匙想，囚門那邊好象有人開門了。\n", jianyu);
		remove_call_out("close_gate");
		call_out("close_gate", 5);
	}
        return 1;
}
void close_gate()
{
	object jianyu;

	if( !query("exits/east") ) return;
        message("vision","鐵門伊咿呀呀一陣想，砰地一聲又關上了。\n", this_object
());
	if( jianyu = find_object(__DIR__"jianyu") )
	{
		message("vision", "鐵門伊咿呀呀一陣想，砰地一聲又關上了。\n", jianyu);
		jianyu->delete("exits/west");
        }
        delete("exits/east");
}

