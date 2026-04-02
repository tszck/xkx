// Room: /d/taohua/tanzhige.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "彈指閣");
	set("long", @LONG
這是一個裏面廊窗的小閣。透過窗縫，可以看到北面的彈指峯。東
面望去，是白浪滔滔的大海，海面上白鷗自由飛來飛去，真是“天高任
鳥飛”啊。閣裏擱着一個橡皮人，滿身標點着穴位(xuedao)，你忍不住
伸指向穴道彈(tan)去。
LONG
	);
        set("exits", ([ 
		"south" : __DIR__"zoulang4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 9020);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_tan", "tan");
}
int do_tan(string arg)
{       
        mapping fam;
	object me = this_player();
	if (arg != "xuedao")
		return notify_fail("你點什麼點啊你？往哪裏點啊你？\n");
	if (!living(me)) return 0;
	if (!(fam = me->query("family")) || fam["family_name"] != "桃花島")
		return notify_fail("你非本島弟子，不能在此練功！\n");

	if ( (int)me->query_skill("finger", 1) > 100)
		return notify_fail("你伸指往橡皮人身上彈去，發現橡皮人太軟了，沒法鍛鍊你的指力。\n");
 
	if((int)me->query("qi")<30)
	{
		me->receive_damage("qi",10);
		write( "你伸指往橡皮人身上彈去，結果一點力氣也沒有，看來是太累了！\n");
		return 1;
	}
	me->receive_damage("qi", random(40));
	me->improve_skill("finger", me->query("int"));
	write("你伸指往橡皮人身上的穴道彈去，彈了個正着！\n");
	return 1;
}