// Room: /d/nanshaolin/jianyu.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "監獄");
	set("long", @LONG
這裏黑沉沉的，即無一絲光亮，也無半分聲息。黑暗中依稀可以看到身
邊似乎有幾個人影，看到你轉過頭去，他們立刻屏住呼吸，緊張地瞪着你。
四壁摸上去冰涼，且極硬，似乎都是鋼鐵鑄成，只有南北面各有一道小門，
門上開了個巴掌大的洞，象是送飯用的。腳邊有一堆東西踢上去克剌剌地散
了開來，細看卻是一具白得發亮的枯骨。
LONG );
	set("valid_startroom",1);
	set("objects",([
		CLASS_D("nanshaolin") + "/fangcheng" : 1,
		"/d/shaolin/obj/fojing1"+random(2) : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6220);
	set("coor/z", 0);
	setup();
}

void init()
{
	object ob = this_player();

	if(userp(ob))
	{
		message("vision", HIY"只聽牢房鐵門匡地一響，一個昏昏沉沉的傢伙被扔了進來！\n\n"NOR, environment(ob), ob);
		tell_object(ob,"方成嘿嘿地笑着：今兒個你可落在我手裏了...！\n");
		ob->set("startroom", "/d/nanshaolin/jianyu");
		ob->apply_condition("nbonze_jail", ob->query_condition("nbonze_jail")+60);
	}
}
