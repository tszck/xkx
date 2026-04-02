// Room: /d/guiyun/zhongting.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

string look_xiao();
string look_zishi();

void create()
{
	set("short","中廳");
	set("long",@LONG
這是歸雲莊的中廳。莊中的大事以及召集弟子訓話都是在這裏進行
的。由於修建年代久遠，看起來已頗為陳舊，但打掃得十分乾淨，光線
也較為充足，完全沒有陳年舊宅的陰晦之氣。四壁掛着一些古人書畫精
品，皆為上乘之作，顯得主人眼光不凡，胸中大有丘壑。
    靠裏面是一張太師椅，椅後的牆上掛着一幅畫(hua)。
LONG );
	set("objects",([
		__DIR__"npc/kezhene" : 1,
		__DIR__"npc/zhucong" : 1,
		__DIR__"npc/hanbaoju" : 1,
		__DIR__"npc/nanxiren" : 1,
		__DIR__"npc/zhangasheng" : 1,
		__DIR__"npc/quanjinfa" : 1,
		__DIR__"npc/hanxiaoying" : 1,
		__DIR__"npc/guanjia" :     1,
		__DIR__"npc/zhuangding3" : 1,
	]));  
	set("exits",([
		"east"  : __DIR__"qianting",
		"north" : __DIR__"zoulang1",
		"south" : __DIR__"zoulang4",
	]) );
	set("item_desc", ([
		"hua" :  "畫中是一位形貌清矍的青衫老者，正在吹簫(xiao)，但是他的姿勢(zishi)卻有點奇怪。\n",
		"xiao" : (: look_xiao :),
		"zishi" : (: look_zishi :),
	]) );

	set("no_clean_up",0);
	setup();
}

string look_xiao()
{
        object me = this_player();

	if (!me->query_temp("guiyun_hua")) return "畫中老人拿簫的姿勢甚是怪異！\n";
	me->set_temp("guiyun_hua", 2);
	return "原來畫中老人竟是把手中握着的簫當作了劍來舞。\n";
}

string look_zishi()
{
        object me = this_player();
	int level, exp;

	level = me->query_skill("sword", 1);
	exp = me->query("combat_exp");
	if (me->query_temp("guiyun_hua") < 2)
	{
		me->set_temp("guiyun_hua", 1);
		return "你仔細地端詳着畫中老人的身姿，恍惚間彷彿看見老人正在緩緩舞動着什麼。\n";
	}
	else
	{
		write("原來畫中老人舞簫的姿勢裏竟然暗藏着高深的劍法！\n");
		if (me->is_busy())
		{
			write("可惜你現在正忙着做別的事，無法專心研究這幅畫。\n");
			return "";
		}
		if( me->is_fighting() ) {
			write("可惜你現在正在戰鬥中，無法專心研究這幅畫。\n");
			return "";
		}
		if (me->query("jing") < 30) 
			return "可惜你太累了，無法集中精神來研究這幅畫。\n";
		if (me->query_skill("sword", 1) > 100) 
			return "這幅在以前的你看來很艱深的畫對現在的你而言已經沒有什麼可值得研究的了。\n";
		if ((int)me->query_skill("sword", 1) < 30 )
			return "你努力試圖從畫中老人的身姿裏看出些什麼，卻發現一切都是徒勞的。\n";
	
		me->receive_damage("jing", 25);
		if( level * level * level /10 < exp)
			me->improve_skill("sword", me->query("int"));

		write("你仔細端詳着畫中老人舞簫的身姿。\n");
		if (!random(8))
			tell_room(this_object(), me->name() + "仔細端詳着畫中老人舞簫的身姿。\n", ({me}));
		return "你對劍法運用的微妙之處有了進一步的認識。\n";
	}
}

