// Room: /d/taohua/liangyi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "兩儀");
	set("long", @LONG
這裏是兩儀層，你一走下來，往上的鐵梯就被撤掉了。往下有一道
懸掛着的鐵梯，通向四象層。所謂兩儀，係指陰陽，是世界的二端。雖
然太極渾圓，仍由對立着又統一的二極構成。陰陽之間不停轉化，生生
不息，是世界運行的原動力。然而陰陽之間仍然不是絕對的對立，所謂
陰中有陽，陽中含陰。是故少陽伴太陰而少陰伴太陽，此兩儀生四象。
以八幹四維而論，艮居於東北而為鬼門，謂之陰，坤生於西南而為人門，
謂之陽。
LONG
	);
	set("exits", ([ 
		"northeast" : __DIR__"yin",
		"southwest" : __DIR__"yang",
		"down" : __DIR__"sixiang",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4680);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_save", "save");
	add_action("do_quit", "quit");
}

int do_save()
{
	write("這裏不準存盤！\n");
	return 1;
}

int do_quit()
{
	write("這裏不準退出！\n");
	return 1;
}