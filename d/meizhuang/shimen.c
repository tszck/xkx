// /d/meizhuang/shimen.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "石門");
	set("long", @LONG
這是在一條昏暗潮溼的地道里的一扇石門。牆壁上點着一盞油燈，
發出淡黃色光芒。
LONG
	);
	set("weapon_count",1);
	set("exits", ([ /* sizeof() == 2 */
		"northup" : __DIR__"midao1",
	]));
	set("coor/x", 3510);
	set("coor/y", -1420);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_unlock", "unlock");
}
int do_unlock(string arg)
{
	object ob, midao2;

	if (query("exits/southdown"))
		return notify_fail("這扇石門已經是打開的。\n");
	if (!arg || (arg != "men" && arg != "door"))
		return notify_fail("你要打開什麼？\n");
	if (!(ob = present("gang yaoshi", this_player())))
		return notify_fail("你不會撬鎖。\n");
	if(!( midao2 = find_object(__DIR__"midao2")) )
                midao2 = load_object(__DIR__"midao2");
	if(objectp(midao2))
	{
		set("exits/southdown", __DIR__"midao2");
		message_vision("$N把鋼芯鑰匙插入了一個匙孔，轉了幾轉，向內推動。\n只聽得軋軋聲響，一扇石門緩緩開了。\n", this_player());
		message("vision","只聽一陣鑰匙想，石門那邊好象有人開門了。\n",
 midao2);
        }
	return 1;
}
