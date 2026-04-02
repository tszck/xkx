// /clone/shop/foshan_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "天海樓");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
		"down" : "/d/foshan/majiu",
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
天海樓是佛山城內有名的店鋪，嶺南向來多豪俠之士，此樓內外裝
飾豪放，頗有豪傑之氣。不過店裏的貨櫃上卻空無一物，看樣子已經很
久沒人來打理了。
LONG);
	else
		set("long", @LONG
天海樓是佛山城內有名的店鋪，嶺南向來多豪俠之士，此樓內外裝
飾豪放，頗有豪傑之氣。整個鋪面寬敞明亮，櫃上擺滿了各式各樣、琳
琅滿目的貨物。
LONG);
        return;
}

