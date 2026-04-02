// /clone/shop/kaifeng_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "福興齋");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/kaifeng/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}

void init()
{
	if (query("shop_type") == 0)
		set("long", @LONG
這裏是開封城內有名的店鋪福興齋，開封爲百年古都，民衆富饒。
店鋪內裝飾得非常豪華，不過櫃上卻空無一物。夥計在一旁打着盹，看
樣子已經很久沒人來打理了。
LONG);
	else
		set("long", @LONG
這裏是開封城內有名的店鋪福興齋，店堂里人來人往，川流不息。
開封爲百年古都，出售的物品也是別具一格。鋪面寬敞明亮，櫃上擺滿
了各式各樣、琳琅滿目的貨物。
LONG);
        return;
}

