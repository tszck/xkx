// /clone/shop/changan_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "同盛祥");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/changan/majiu",
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
這裏是長安城裏小有名氣的店堂——同盛祥。長安城民衆富裕，鋪
裏出售的貨物也是別具一格。整個鋪面裝潢得非常雅緻，不過貨櫃上卻
空無一物，看來已很久沒人打理了。
LONG);
	else
		set("long", @LONG
這裏是長安城裏小有名氣的店堂——同盛祥。長安城民衆富裕，鋪
裏出售的貨物也是別具一格。整個鋪面裝潢得非常雅緻。貨櫃上擺滿了
各式各樣、琳琅滿目的貨物。
LONG);
        return;
}
