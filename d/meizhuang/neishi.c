// /d/meizhuang/xiaowu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "內室");
	set("long", @LONG
室內一牀一幾，陳設簡單，牀上掛了的紗帳，鋪着的被褥，均甚是
陳舊，已呈黃色。几上放着一張短琴，通體黝黑，似是鐵製。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"xiaowu",
	]));
	set("item_desc", ([
		"chuang" : "這是一張很陳舊的木牀。\n" ,
		"牀"     : "這是一張很陳舊的木牀。\n" ,
		"beiru"  : "這是一牀鋪在牀上的舊被褥。\n" ,
		"被褥"   : "這是一牀鋪在牀上的舊被褥。\n" ,
	]));
	set("coor/x", 3510);
	set("coor/y", -1410);
	set("coor/z", 20);
	setup();
}

void init()
{
        add_action("do_move", "xian");
        add_action("do_move", "move");
        add_action("do_open", "open");
        add_action("do_open", "ti");
}
int do_move(string arg)
{
	object me = this_player();

	if (!arg||arg!="beiru") return notify_fail("你要掀開什麼？\n");
	if ( query("beiru") )
		return notify_fail("被褥已經掀開了，再掀就掉地上了！\n");
	message_vision("$N掀開牀上被褥，揭起牀板，下面卻是塊鐵板，上有銅環。\n", me);
	set("beiru", 1);
	return 1;
}

int do_open(string arg)
{
	object midao1, me = this_player();

	if (!arg||arg!="tieban") return notify_fail("你要提開什麼？\n");
	if (me->query("neili") < 200)
	{
		message_vision("$N握住銅環，向上一提，鐵板紋風不動。\n", me);
		me->set("neili", 0);
		return 1;
	}
	me->add("neili", -200);
	if(!( midao1 = find_object(__DIR__"midao1")) )
		midao1 = load_object(__DIR__"midao1");
        if(objectp(midao1))
        {
		set("exits/down", __DIR__"midao1");
		message_vision("$N握住銅環，向上一提，一塊四尺來闊、五尺來長的鐵板應手而起，露出一個長大方洞。\n", me);
		midao1->set("exits/up", __FILE__);
                message("vision","頭上透出一點光，好象是上面有人打開鐵板了。\n", midao1);
                remove_call_out("close_gate");
                call_out("close_gate", 5);
        }
	return 1;
}
void close_gate()
{
	if( !query("exits/down") ) return;
	message("vision","鐵板落下來, 將洞口遮得嚴嚴實實的。\n", this_object());
	delete("exits/down");
}



