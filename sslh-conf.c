/* Generated by conf2struct (https://www.rutschle.net/tech/conf2struct/README)
 * on Sun Jan 27 18:51:35 2019. */

#define _GNU_SOURCE
#include <string.h>
#include <libconfig.h>
#include <stdlib.h>
#include "sslh-conf.h"

static void sslhcfg_protocols_init(struct sslhcfg_protocols_item* cfg) {
        memset(cfg, 0, sizeof(*cfg));
	cfg->fork = 0;
	cfg->log_level = 1;
	cfg->keepalive = 0;
	cfg->minlength = 0;
	cfg->maxlength = 0;
}

static void sslhcfg_listen_init(struct sslhcfg_listen_item* cfg) {
        memset(cfg, 0, sizeof(*cfg));
	cfg->keepalive = 0;
}

static void sslhcfg_init(struct sslhcfg_item* cfg) {
        memset(cfg, 0, sizeof(*cfg));
	cfg->verbose = 0;
	cfg->foreground = 0;
	cfg->inetd = 0;
	cfg->numeric = 0;
	cfg->transparent = 0;
	cfg->timeout = 5;
	cfg->syslog_facility = "auth";
	cfg->on_timeout = "ssh";
}

static int sslhcfg_protocols_parser(
        config_setting_t* cfg, 
        struct sslhcfg_protocols_item* sslhcfg_protocols, 
        const char** errmsg) 
{
        config_setting_t* setting;
        char* tmp;
        *errmsg = NULL;

        sslhcfg_protocols_init(sslhcfg_protocols);

        if (config_setting_lookup(cfg, "name")) {
            if (config_setting_lookup_string(cfg, "name", &sslhcfg_protocols->name) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"name\" failed";
                return 0;
            }
        } else {
            *errmsg = "Mandatory option \"sslhcfg_protocols.name\" is missing";
            return 0;
        }
        if (config_setting_lookup(cfg, "host")) {
            if (config_setting_lookup_string(cfg, "host", &sslhcfg_protocols->host) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"host\" failed";
                return 0;
            }
        } else {
            *errmsg = "Mandatory option \"sslhcfg_protocols.host\" is missing";
            return 0;
        }
        if (asprintf(&tmp, "%s", sslhcfg_protocols->host) == -1) {
            *errmsg = "asprintf: cannot allocate memory";
            return 0;
        }
        sslhcfg_protocols->host = tmp;
        if (config_setting_lookup(cfg, "port")) {
            if (config_setting_lookup_string(cfg, "port", &sslhcfg_protocols->port) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"port\" failed";
                return 0;
            }
        } else {
            *errmsg = "Mandatory option \"sslhcfg_protocols.port\" is missing";
            return 0;
        }
        if (asprintf(&tmp, "%s", sslhcfg_protocols->port) == -1) {
            *errmsg = "asprintf: cannot allocate memory";
            return 0;
        }
        sslhcfg_protocols->port = tmp;
        if (config_setting_lookup(cfg, "service")) {
            if (config_setting_lookup_string(cfg, "service", &sslhcfg_protocols->service) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"service\" failed";
                return 0;
            } else {
		sslhcfg_protocols->service_is_present = 1;
	}
;
        }
        if (config_setting_lookup(cfg, "fork")) {
            if (config_setting_lookup_bool(cfg, "fork", &sslhcfg_protocols->fork) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"fork\" failed";
                return 0;
            } ;
        }
        if (config_setting_lookup(cfg, "log_level")) {
            if (config_setting_lookup_int(cfg, "log_level", &sslhcfg_protocols->log_level) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"log_level\" failed";
                return 0;
            } ;
        }
        if (config_setting_lookup(cfg, "keepalive")) {
            if (config_setting_lookup_bool(cfg, "keepalive", &sslhcfg_protocols->keepalive) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"keepalive\" failed";
                return 0;
            } ;
        }
        sslhcfg_protocols->sni_hostnames = NULL;
        sslhcfg_protocols->sni_hostnames_len = 0;
        if ((setting = config_setting_lookup(cfg, "sni_hostnames"))) {
            int len = config_setting_length(setting);
            sslhcfg_protocols->sni_hostnames = malloc(len * sizeof(*sslhcfg_protocols->sni_hostnames));
            sslhcfg_protocols->sni_hostnames_len = len;
            for (int i = 0; i < len; i++) {
                config_setting_t* s = config_setting_get_elem(setting, i);
                sslhcfg_protocols->sni_hostnames[i] = config_setting_get_string(s);
            }
        }
        sslhcfg_protocols->alpn_protocols = NULL;
        sslhcfg_protocols->alpn_protocols_len = 0;
        if ((setting = config_setting_lookup(cfg, "alpn_protocols"))) {
            int len = config_setting_length(setting);
            sslhcfg_protocols->alpn_protocols = malloc(len * sizeof(*sslhcfg_protocols->alpn_protocols));
            sslhcfg_protocols->alpn_protocols_len = len;
            for (int i = 0; i < len; i++) {
                config_setting_t* s = config_setting_get_elem(setting, i);
                sslhcfg_protocols->alpn_protocols[i] = config_setting_get_string(s);
            }
        }
        sslhcfg_protocols->regex_patterns = NULL;
        sslhcfg_protocols->regex_patterns_len = 0;
        if ((setting = config_setting_lookup(cfg, "regex_patterns"))) {
            int len = config_setting_length(setting);
            sslhcfg_protocols->regex_patterns = malloc(len * sizeof(*sslhcfg_protocols->regex_patterns));
            sslhcfg_protocols->regex_patterns_len = len;
            for (int i = 0; i < len; i++) {
                config_setting_t* s = config_setting_get_elem(setting, i);
                sslhcfg_protocols->regex_patterns[i] = config_setting_get_string(s);
            }
        }
        if (config_setting_lookup(cfg, "minlength")) {
            if (config_setting_lookup_int(cfg, "minlength", &sslhcfg_protocols->minlength) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"minlength\" failed";
                return 0;
            } ;
        }
        if (config_setting_lookup(cfg, "maxlength")) {
            if (config_setting_lookup_int(cfg, "maxlength", &sslhcfg_protocols->maxlength) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"maxlength\" failed";
                return 0;
            } ;
        }
	return 1;
}

static int sslhcfg_listen_parser(
        config_setting_t* cfg, 
        struct sslhcfg_listen_item* sslhcfg_listen, 
        const char** errmsg) 
{
        config_setting_t* setting;
        char* tmp;
        *errmsg = NULL;

        sslhcfg_listen_init(sslhcfg_listen);

        if (config_setting_lookup(cfg, "host")) {
            if (config_setting_lookup_string(cfg, "host", &sslhcfg_listen->host) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"host\" failed";
                return 0;
            }
        } else {
            *errmsg = "Mandatory option \"sslhcfg_listen.host\" is missing";
            return 0;
        }
        if (asprintf(&tmp, "%s", sslhcfg_listen->host) == -1) {
            *errmsg = "asprintf: cannot allocate memory";
            return 0;
        }
        sslhcfg_listen->host = tmp;
        if (config_setting_lookup(cfg, "port")) {
            if (config_setting_lookup_string(cfg, "port", &sslhcfg_listen->port) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"port\" failed";
                return 0;
            }
        } else {
            *errmsg = "Mandatory option \"sslhcfg_listen.port\" is missing";
            return 0;
        }
        if (asprintf(&tmp, "%s", sslhcfg_listen->port) == -1) {
            *errmsg = "asprintf: cannot allocate memory";
            return 0;
        }
        sslhcfg_listen->port = tmp;
        if (config_setting_lookup(cfg, "keepalive")) {
            if (config_setting_lookup_bool(cfg, "keepalive", &sslhcfg_listen->keepalive) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"keepalive\" failed";
                return 0;
            } ;
        }
	return 1;
}

static int sslhcfg_parser(
        config_setting_t* cfg, 
        struct sslhcfg_item* sslhcfg, 
        const char** errmsg) 
{
        config_setting_t* setting;
        char* tmp;
        *errmsg = NULL;

        sslhcfg_init(sslhcfg);

        if (config_setting_lookup(cfg, "verbose")) {
            if (config_setting_lookup_int(cfg, "verbose", &sslhcfg->verbose) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"verbose\" failed";
                return 0;
            } ;
        }
        if (config_setting_lookup(cfg, "foreground")) {
            if (config_setting_lookup_bool(cfg, "foreground", &sslhcfg->foreground) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"foreground\" failed";
                return 0;
            } ;
        }
        if (config_setting_lookup(cfg, "inetd")) {
            if (config_setting_lookup_bool(cfg, "inetd", &sslhcfg->inetd) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"inetd\" failed";
                return 0;
            } ;
        }
        if (config_setting_lookup(cfg, "numeric")) {
            if (config_setting_lookup_bool(cfg, "numeric", &sslhcfg->numeric) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"numeric\" failed";
                return 0;
            } ;
        }
        if (config_setting_lookup(cfg, "transparent")) {
            if (config_setting_lookup_bool(cfg, "transparent", &sslhcfg->transparent) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"transparent\" failed";
                return 0;
            } ;
        }
        if (config_setting_lookup(cfg, "timeout")) {
            if (config_setting_lookup_int(cfg, "timeout", &sslhcfg->timeout) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"timeout\" failed";
                return 0;
            } ;
        }
        if (config_setting_lookup(cfg, "user")) {
            if (config_setting_lookup_string(cfg, "user", &sslhcfg->user) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"user\" failed";
                return 0;
            } else {
		sslhcfg->user_is_present = 1;
	}
;
        }
        if (config_setting_lookup(cfg, "pidfile")) {
            if (config_setting_lookup_string(cfg, "pidfile", &sslhcfg->pidfile) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"pidfile\" failed";
                return 0;
            } else {
		sslhcfg->pidfile_is_present = 1;
	}
;
        }
        if (config_setting_lookup(cfg, "chroot")) {
            if (config_setting_lookup_string(cfg, "chroot", &sslhcfg->chroot) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"chroot\" failed";
                return 0;
            } else {
		sslhcfg->chroot_is_present = 1;
	}
;
        }
        if (config_setting_lookup(cfg, "syslog_facility")) {
            if (config_setting_lookup_string(cfg, "syslog_facility", &sslhcfg->syslog_facility) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"syslog_facility\" failed";
                return 0;
            } ;
        }
        if (config_setting_lookup(cfg, "on_timeout")) {
            if (config_setting_lookup_string(cfg, "on_timeout", &sslhcfg->on_timeout) == CONFIG_FALSE) {
                *errmsg = "Parsing of option \"on_timeout\" failed";
                return 0;
            } ;
        }

        sslhcfg->listen = NULL;
        sslhcfg->listen_len = 0;
        if ((setting = config_setting_lookup(cfg, "listen"))) {
            int len = config_setting_length(setting);
            sslhcfg->listen = malloc(len * sizeof(*sslhcfg->listen));
            sslhcfg->listen_len = len;
            for (int i = 0; i < len; i++) {
                config_setting_t* s = config_setting_get_elem(setting, i);
                int res = sslhcfg_listen_parser(s, &sslhcfg->listen[i], errmsg);
                if (!res) return 0;
            }
        }

        sslhcfg->protocols = NULL;
        sslhcfg->protocols_len = 0;
        if ((setting = config_setting_lookup(cfg, "protocols"))) {
            int len = config_setting_length(setting);
            sslhcfg->protocols = malloc(len * sizeof(*sslhcfg->protocols));
            sslhcfg->protocols_len = len;
            for (int i = 0; i < len; i++) {
                config_setting_t* s = config_setting_get_elem(setting, i);
                int res = sslhcfg_protocols_parser(s, &sslhcfg->protocols[i], errmsg);
                if (!res) return 0;
            }
        }
	return 1;
}

/* Public parser API: returns 0 on failure, 1 on success */
int sslhcfg_parse_file(const char* filename, struct sslhcfg_item* cfg, const char**errmsg)
{
    config_t c;

    config_init(&c);
    if (config_read_file(&c, filename) == CONFIG_FALSE) {
        if (config_error_line(&c) != 0) {
           asprintf(errmsg, "%s:%d:%s", 
                    filename,
                    config_error_line(&c),
                    config_error_text(&c));
           return 0;
        }
        asprintf(errmsg, "%s:%s", filename, config_error_text(&c));
        return 0;
    }
    return sslhcfg_parser(config_lookup(&c, "/"), cfg, errmsg);
}

static void indent(int depth) 
{
    int i;
    for (i = 0; i < depth; i++)
        printf("    ");
}

static void sslhcfg_protocols_print(
        struct sslhcfg_protocols_item* sslhcfg_protocols,
        int depth) 
{
        int i;
        indent(depth);
        printf("name: %s\n", sslhcfg_protocols->name);
        indent(depth);
        printf("host: %s\n", sslhcfg_protocols->host);
        indent(depth);
        printf("port: %s\n", sslhcfg_protocols->port);
        indent(depth);
        printf("service: %s\n", sslhcfg_protocols->service);
        indent(depth);
        printf("fork: %d\n", sslhcfg_protocols->fork);
        indent(depth);
        printf("log_level: %d\n", sslhcfg_protocols->log_level);
        indent(depth);
        printf("keepalive: %d\n", sslhcfg_protocols->keepalive);
        indent(depth);
        printf("sni_hostnames [%d]:\n", sslhcfg_protocols->sni_hostnames_len);
        for (i = 0; i < sslhcfg_protocols->sni_hostnames_len; i++) {
            indent(depth+1);
            printf("%d:\t%s\n", i, sslhcfg_protocols->sni_hostnames[i]);
        }
        indent(depth);
        printf("alpn_protocols [%d]:\n", sslhcfg_protocols->alpn_protocols_len);
        for (i = 0; i < sslhcfg_protocols->alpn_protocols_len; i++) {
            indent(depth+1);
            printf("%d:\t%s\n", i, sslhcfg_protocols->alpn_protocols[i]);
        }
        indent(depth);
        printf("regex_patterns [%d]:\n", sslhcfg_protocols->regex_patterns_len);
        for (i = 0; i < sslhcfg_protocols->regex_patterns_len; i++) {
            indent(depth+1);
            printf("%d:\t%s\n", i, sslhcfg_protocols->regex_patterns[i]);
        }
        indent(depth);
        printf("minlength: %d\n", sslhcfg_protocols->minlength);
        indent(depth);
        printf("maxlength: %d\n", sslhcfg_protocols->maxlength);
}

static void sslhcfg_listen_print(
        struct sslhcfg_listen_item* sslhcfg_listen,
        int depth) 
{
        int i;
        indent(depth);
        printf("host: %s\n", sslhcfg_listen->host);
        indent(depth);
        printf("port: %s\n", sslhcfg_listen->port);
        indent(depth);
        printf("keepalive: %d\n", sslhcfg_listen->keepalive);
}

void sslhcfg_print(
        struct sslhcfg_item* sslhcfg,
        int depth) 
{
        int i;
        indent(depth);
        printf("verbose: %d\n", sslhcfg->verbose);
        indent(depth);
        printf("foreground: %d\n", sslhcfg->foreground);
        indent(depth);
        printf("inetd: %d\n", sslhcfg->inetd);
        indent(depth);
        printf("numeric: %d\n", sslhcfg->numeric);
        indent(depth);
        printf("transparent: %d\n", sslhcfg->transparent);
        indent(depth);
        printf("timeout: %d\n", sslhcfg->timeout);
        indent(depth);
        printf("user: %s\n", sslhcfg->user);
        indent(depth);
        printf("pidfile: %s\n", sslhcfg->pidfile);
        indent(depth);
        printf("chroot: %s\n", sslhcfg->chroot);
        indent(depth);
        printf("syslog_facility: %s\n", sslhcfg->syslog_facility);
        indent(depth);
        printf("on_timeout: %s\n", sslhcfg->on_timeout);

        indent(depth);
        printf("listen [%d]:\n", sslhcfg->listen_len);
        for (int i = 0; i < sslhcfg->listen_len; i++) {
            sslhcfg_listen_print(&sslhcfg->listen[i], depth+1);
        }

        indent(depth);
        printf("protocols [%d]:\n", sslhcfg->protocols_len);
        for (int i = 0; i < sslhcfg->protocols_len; i++) {
            sslhcfg_protocols_print(&sslhcfg->protocols[i], depth+1);
        }
}

#include "argtable3.h"
#include <regex.h>

struct arg_file* sslhcfg_conffile;
 struct arg_int* sslhcfg_verbose;
 struct arg_lit* sslhcfg_foreground;
 struct arg_lit* sslhcfg_inetd;
 struct arg_lit* sslhcfg_numeric;
 struct arg_lit* sslhcfg_transparent;
 struct arg_int* sslhcfg_timeout;
 struct arg_str* sslhcfg_user;
 struct arg_str* sslhcfg_pidfile;
 struct arg_str* sslhcfg_chroot;
 struct arg_str* sslhcfg_syslog_facility;
 struct arg_str* sslhcfg_on_timeout;
 	struct arg_str* sslhcfg_listen;
 	struct arg_str* sslhcfg_ssh;
 	struct arg_str* sslhcfg_tls;
 	struct arg_str* sslhcfg_openvpn;
 	struct arg_str* sslhcfg_tinc;
 	struct arg_str* sslhcfg_xmpp;
 	struct arg_str* sslhcfg_http;
 	struct arg_str* sslhcfg_adb;
 	struct arg_str* sslhcfg_socks5;

struct arg_end* sslhcfg_end;


static void sslhcfg_cl_c2s(int arg_index, struct sslhcfg_item* cfg) {
    int i, len;

	if (sslhcfg_verbose->count) {
		cfg->verbose = sslhcfg_verbose->ival [arg_index];
	}
	if (sslhcfg_foreground->count) {
		cfg->foreground = sslhcfg_foreground->count;
	}
	if (sslhcfg_inetd->count) {
		cfg->inetd = sslhcfg_inetd->count;
	}
	if (sslhcfg_numeric->count) {
		cfg->numeric = sslhcfg_numeric->count;
	}
	if (sslhcfg_transparent->count) {
		cfg->transparent = sslhcfg_transparent->count;
	}
	if (sslhcfg_timeout->count) {
		cfg->timeout = sslhcfg_timeout->ival [arg_index];
	}
	if (sslhcfg_user->count) {
		cfg->user_is_present = 1;
		cfg->user = sslhcfg_user->sval [arg_index];
	}
	if (sslhcfg_pidfile->count) {
		cfg->pidfile_is_present = 1;
		cfg->pidfile = sslhcfg_pidfile->sval [arg_index];
	}
	if (sslhcfg_chroot->count) {
		cfg->chroot_is_present = 1;
		cfg->chroot = sslhcfg_chroot->sval [arg_index];
	}
	if (sslhcfg_syslog_facility->count) {
		cfg->syslog_facility = sslhcfg_syslog_facility->sval [arg_index];
	}
	if (sslhcfg_on_timeout->count) {
		cfg->on_timeout = sslhcfg_on_timeout->sval [arg_index];
	}
}



int sslhcfg_cl_parse(int argc, char* argv[], struct sslhcfg_item* cfg) {
        void* argtable[] = {
        sslhcfg_conffile = arg_filen("F", "conffile", "<file>", 0, 1, "Specify configuration file"),
         sslhcfg_verbose = arg_intn("v", "verbose", "<n>", 0, 1, ""),
         sslhcfg_foreground = arg_litn("f", "foreground", 0, 1, "Run in foreground instead of as a daemon"),
         sslhcfg_inetd = arg_litn("i", "inetd", 0, 1, "Run in inetd mode: use stdin/stdout instead of network listen"),
         sslhcfg_numeric = arg_litn("n", "numeric", 0, 1, "Print IP addresses and ports as numbers"),
         sslhcfg_transparent = arg_litn(NULL, "transparent", 0, 1, "Set up as a transparent proxy"),
         sslhcfg_timeout = arg_intn("t", "timeout", "<n>", 0, 1, "Set up timeout before connecting to default target"),
         sslhcfg_user = arg_strn("u", "user", "<str>", 0, 1, "Username to change to after set-up"),
         sslhcfg_pidfile = arg_strn("P", "pidfile", "<file>", 0, 1, "Path to file to store PID of current instance"),
         sslhcfg_chroot = arg_strn("C", "chroot", "<path>", 0, 1, "Root to change to after set-up"),
         sslhcfg_syslog_facility = arg_strn(NULL, "syslog-facility", "<str>", 0, 1, "Facility to syslog to"),
         sslhcfg_on_timeout = arg_strn(NULL, "on-timeout", "<str>", 0, 1, "Target to connect to when timing out"),
 	sslhcfg_listen = arg_strn("p", "listen", "<host:port>", 0, 10, "Listen on host:port"),
 	sslhcfg_ssh = arg_strn(NULL, "ssh", "<host:port>", 0, 10, "Set up ssh target"),
 	sslhcfg_tls = arg_strn(NULL, "tls", "<host:port>", 0, 10, "Set up TLS/SSL target"),
 	sslhcfg_openvpn = arg_strn(NULL, "openvpn", "<host:port>", 0, 10, "Set up OpenVPN target"),
 	sslhcfg_tinc = arg_strn(NULL, "tinc", "<host:port>", 0, 10, "Set up tinc target"),
 	sslhcfg_xmpp = arg_strn(NULL, "xmpp", "<host:port>", 0, 10, "Set up XMPP target"),
 	sslhcfg_http = arg_strn(NULL, "http", "<host:port>", 0, 10, "Set up HTTP (plain) target"),
 	sslhcfg_adb = arg_strn(NULL, "adb", "<host:port>", 0, 10, "Set up ADB (Android Debug) target"),
 	sslhcfg_socks5 = arg_strn(NULL, "socks5", "<host:port>", 0, 10, "Set up socks5 target"),

        sslhcfg_end = arg_end(10)
    };
    const char* errmsg;
    int nerrors, cl_i;

    nerrors = arg_parse(argc, argv, argtable);
    if (nerrors) {
        arg_print_errors(stdout, sslhcfg_end, "sslhcfg"); 
        arg_print_syntax(stdout, argtable, "\n");
        arg_print_glossary(stdout, argtable, "  %-25s	%s\n");
        return 0;
    }

    if (sslhcfg_conffile->count) {
        if (!sslhcfg_parse_file(sslhcfg_conffile->filename[0], cfg, &errmsg)) {
            fprintf(stderr, "%s\n", errmsg);
            exit(1);
        }
    }

    sslhcfg_cl_c2s(0, cfg);

#define MAX_MATCH 10
    for (cl_i = 0; cl_i < sslhcfg_listen->count; cl_i++) {
        regex_t preg;
        regmatch_t pmatch[MAX_MATCH];
        int res = regcomp(&preg, "(\\w+):(\\w+)", REG_EXTENDED);
        if (res) {
            int errlen = regerror(res, &preg, NULL, 0);
            char* errmsg = malloc(errlen);
            regerror(res, &preg, errmsg, errlen);

            fprintf(stderr, "(\\w+):(\\w+): %s\n", errmsg);
            exit(1);
        }
        res = regexec(&preg, sslhcfg_listen->sval [cl_i], MAX_MATCH, &pmatch[0], 0);
        if (res) {
            fprintf(stderr, "--listen %s: Illegal argument\n", sslhcfg_listen->sval [cl_i]);
            exit(1);
        }
        
        int param_len, i, found = -1;
        struct sslhcfg_listen_item* group;

/* No search for override */        if (found == -1) {
            cfg->listen_len++;
            cfg->listen = realloc(cfg->listen, cfg->listen_len * sizeof(*cfg->listen));
            group = & cfg->listen [cfg->listen_len - 1];
        } else {
            group = & cfg->listen [found];
        }


        sslhcfg_listen_init(group);
        param_len = pmatch[1].rm_eo - pmatch[1].rm_so;
        group->host = calloc(1, param_len + 1);
        memcpy(group->host, sslhcfg_listen->sval [cl_i]+pmatch[1].rm_so, param_len);
        param_len = pmatch[2].rm_eo - pmatch[2].rm_so;
        group->port = calloc(1, param_len + 1);
        memcpy(group->port, sslhcfg_listen->sval [cl_i]+pmatch[2].rm_so, param_len);
    }
#define MAX_MATCH 10
    for (cl_i = 0; cl_i < sslhcfg_ssh->count; cl_i++) {
        regex_t preg;
        regmatch_t pmatch[MAX_MATCH];
        int res = regcomp(&preg, "(\\w+):(\\w+)", REG_EXTENDED);
        if (res) {
            int errlen = regerror(res, &preg, NULL, 0);
            char* errmsg = malloc(errlen);
            regerror(res, &preg, errmsg, errlen);

            fprintf(stderr, "(\\w+):(\\w+): %s\n", errmsg);
            exit(1);
        }
        res = regexec(&preg, sslhcfg_ssh->sval [cl_i], MAX_MATCH, &pmatch[0], 0);
        if (res) {
            fprintf(stderr, "--ssh %s: Illegal argument\n", sslhcfg_ssh->sval [cl_i]);
            exit(1);
        }
        
        int param_len, i, found = -1;
        struct sslhcfg_protocols_item* group;

        for (i = 0; i < cfg->protocols_len; i++) {
            if (!strncmp(cfg->protocols [i].name, "ssh",
                         3)) {
                found = i;
                break;
            }
        }
        if (found == -1) {
            cfg->protocols_len++;
            cfg->protocols = realloc(cfg->protocols, cfg->protocols_len * sizeof(*cfg->protocols));
            group = & cfg->protocols [cfg->protocols_len - 1];
        } else {
            group = & cfg->protocols [found];
        }


        sslhcfg_protocols_init(group);
        param_len = 3;
        group->name = calloc(1, param_len + 1);
        memcpy(group->name, "ssh", param_len);
        param_len = pmatch[1].rm_eo - pmatch[1].rm_so;
        group->host = calloc(1, param_len + 1);
        memcpy(group->host, sslhcfg_ssh->sval [cl_i]+pmatch[1].rm_so, param_len);
        param_len = pmatch[2].rm_eo - pmatch[2].rm_so;
        group->port = calloc(1, param_len + 1);
        memcpy(group->port, sslhcfg_ssh->sval [cl_i]+pmatch[2].rm_so, param_len);
    }
#define MAX_MATCH 10
    for (cl_i = 0; cl_i < sslhcfg_tls->count; cl_i++) {
        regex_t preg;
        regmatch_t pmatch[MAX_MATCH];
        int res = regcomp(&preg, "(\\w+):(\\w+)", REG_EXTENDED);
        if (res) {
            int errlen = regerror(res, &preg, NULL, 0);
            char* errmsg = malloc(errlen);
            regerror(res, &preg, errmsg, errlen);

            fprintf(stderr, "(\\w+):(\\w+): %s\n", errmsg);
            exit(1);
        }
        res = regexec(&preg, sslhcfg_tls->sval [cl_i], MAX_MATCH, &pmatch[0], 0);
        if (res) {
            fprintf(stderr, "--tls %s: Illegal argument\n", sslhcfg_tls->sval [cl_i]);
            exit(1);
        }
        
        int param_len, i, found = -1;
        struct sslhcfg_protocols_item* group;

        for (i = 0; i < cfg->protocols_len; i++) {
            if (!strncmp(cfg->protocols [i].name, "tls",
                         3)) {
                found = i;
                break;
            }
        }
        if (found == -1) {
            cfg->protocols_len++;
            cfg->protocols = realloc(cfg->protocols, cfg->protocols_len * sizeof(*cfg->protocols));
            group = & cfg->protocols [cfg->protocols_len - 1];
        } else {
            group = & cfg->protocols [found];
        }


        sslhcfg_protocols_init(group);
        param_len = 3;
        group->name = calloc(1, param_len + 1);
        memcpy(group->name, "tls", param_len);
        param_len = pmatch[1].rm_eo - pmatch[1].rm_so;
        group->host = calloc(1, param_len + 1);
        memcpy(group->host, sslhcfg_tls->sval [cl_i]+pmatch[1].rm_so, param_len);
        param_len = pmatch[2].rm_eo - pmatch[2].rm_so;
        group->port = calloc(1, param_len + 1);
        memcpy(group->port, sslhcfg_tls->sval [cl_i]+pmatch[2].rm_so, param_len);
    }
#define MAX_MATCH 10
    for (cl_i = 0; cl_i < sslhcfg_openvpn->count; cl_i++) {
        regex_t preg;
        regmatch_t pmatch[MAX_MATCH];
        int res = regcomp(&preg, "(\\w+):(\\w+)", REG_EXTENDED);
        if (res) {
            int errlen = regerror(res, &preg, NULL, 0);
            char* errmsg = malloc(errlen);
            regerror(res, &preg, errmsg, errlen);

            fprintf(stderr, "(\\w+):(\\w+): %s\n", errmsg);
            exit(1);
        }
        res = regexec(&preg, sslhcfg_openvpn->sval [cl_i], MAX_MATCH, &pmatch[0], 0);
        if (res) {
            fprintf(stderr, "--openvpn %s: Illegal argument\n", sslhcfg_openvpn->sval [cl_i]);
            exit(1);
        }
        
        int param_len, i, found = -1;
        struct sslhcfg_protocols_item* group;

        for (i = 0; i < cfg->protocols_len; i++) {
            if (!strncmp(cfg->protocols [i].name, "openvpn",
                         7)) {
                found = i;
                break;
            }
        }
        if (found == -1) {
            cfg->protocols_len++;
            cfg->protocols = realloc(cfg->protocols, cfg->protocols_len * sizeof(*cfg->protocols));
            group = & cfg->protocols [cfg->protocols_len - 1];
        } else {
            group = & cfg->protocols [found];
        }


        sslhcfg_protocols_init(group);
        param_len = 7;
        group->name = calloc(1, param_len + 1);
        memcpy(group->name, "openvpn", param_len);
        param_len = pmatch[1].rm_eo - pmatch[1].rm_so;
        group->host = calloc(1, param_len + 1);
        memcpy(group->host, sslhcfg_openvpn->sval [cl_i]+pmatch[1].rm_so, param_len);
        param_len = pmatch[2].rm_eo - pmatch[2].rm_so;
        group->port = calloc(1, param_len + 1);
        memcpy(group->port, sslhcfg_openvpn->sval [cl_i]+pmatch[2].rm_so, param_len);
    }
#define MAX_MATCH 10
    for (cl_i = 0; cl_i < sslhcfg_tinc->count; cl_i++) {
        regex_t preg;
        regmatch_t pmatch[MAX_MATCH];
        int res = regcomp(&preg, "(\\w+):(\\w+)", REG_EXTENDED);
        if (res) {
            int errlen = regerror(res, &preg, NULL, 0);
            char* errmsg = malloc(errlen);
            regerror(res, &preg, errmsg, errlen);

            fprintf(stderr, "(\\w+):(\\w+): %s\n", errmsg);
            exit(1);
        }
        res = regexec(&preg, sslhcfg_tinc->sval [cl_i], MAX_MATCH, &pmatch[0], 0);
        if (res) {
            fprintf(stderr, "--tinc %s: Illegal argument\n", sslhcfg_tinc->sval [cl_i]);
            exit(1);
        }
        
        int param_len, i, found = -1;
        struct sslhcfg_protocols_item* group;

        for (i = 0; i < cfg->protocols_len; i++) {
            if (!strncmp(cfg->protocols [i].name, "openvpn",
                         7)) {
                found = i;
                break;
            }
        }
        if (found == -1) {
            cfg->protocols_len++;
            cfg->protocols = realloc(cfg->protocols, cfg->protocols_len * sizeof(*cfg->protocols));
            group = & cfg->protocols [cfg->protocols_len - 1];
        } else {
            group = & cfg->protocols [found];
        }


        sslhcfg_protocols_init(group);
        param_len = 7;
        group->name = calloc(1, param_len + 1);
        memcpy(group->name, "openvpn", param_len);
        param_len = pmatch[1].rm_eo - pmatch[1].rm_so;
        group->host = calloc(1, param_len + 1);
        memcpy(group->host, sslhcfg_tinc->sval [cl_i]+pmatch[1].rm_so, param_len);
        param_len = pmatch[2].rm_eo - pmatch[2].rm_so;
        group->port = calloc(1, param_len + 1);
        memcpy(group->port, sslhcfg_tinc->sval [cl_i]+pmatch[2].rm_so, param_len);
    }
#define MAX_MATCH 10
    for (cl_i = 0; cl_i < sslhcfg_xmpp->count; cl_i++) {
        regex_t preg;
        regmatch_t pmatch[MAX_MATCH];
        int res = regcomp(&preg, "(\\w+):(\\w+)", REG_EXTENDED);
        if (res) {
            int errlen = regerror(res, &preg, NULL, 0);
            char* errmsg = malloc(errlen);
            regerror(res, &preg, errmsg, errlen);

            fprintf(stderr, "(\\w+):(\\w+): %s\n", errmsg);
            exit(1);
        }
        res = regexec(&preg, sslhcfg_xmpp->sval [cl_i], MAX_MATCH, &pmatch[0], 0);
        if (res) {
            fprintf(stderr, "--xmpp %s: Illegal argument\n", sslhcfg_xmpp->sval [cl_i]);
            exit(1);
        }
        
        int param_len, i, found = -1;
        struct sslhcfg_protocols_item* group;

        for (i = 0; i < cfg->protocols_len; i++) {
            if (!strncmp(cfg->protocols [i].name, "xmpp",
                         4)) {
                found = i;
                break;
            }
        }
        if (found == -1) {
            cfg->protocols_len++;
            cfg->protocols = realloc(cfg->protocols, cfg->protocols_len * sizeof(*cfg->protocols));
            group = & cfg->protocols [cfg->protocols_len - 1];
        } else {
            group = & cfg->protocols [found];
        }


        sslhcfg_protocols_init(group);
        param_len = 4;
        group->name = calloc(1, param_len + 1);
        memcpy(group->name, "xmpp", param_len);
        param_len = pmatch[1].rm_eo - pmatch[1].rm_so;
        group->host = calloc(1, param_len + 1);
        memcpy(group->host, sslhcfg_xmpp->sval [cl_i]+pmatch[1].rm_so, param_len);
        param_len = pmatch[2].rm_eo - pmatch[2].rm_so;
        group->port = calloc(1, param_len + 1);
        memcpy(group->port, sslhcfg_xmpp->sval [cl_i]+pmatch[2].rm_so, param_len);
    }
#define MAX_MATCH 10
    for (cl_i = 0; cl_i < sslhcfg_http->count; cl_i++) {
        regex_t preg;
        regmatch_t pmatch[MAX_MATCH];
        int res = regcomp(&preg, "(\\w+):(\\w+)", REG_EXTENDED);
        if (res) {
            int errlen = regerror(res, &preg, NULL, 0);
            char* errmsg = malloc(errlen);
            regerror(res, &preg, errmsg, errlen);

            fprintf(stderr, "(\\w+):(\\w+): %s\n", errmsg);
            exit(1);
        }
        res = regexec(&preg, sslhcfg_http->sval [cl_i], MAX_MATCH, &pmatch[0], 0);
        if (res) {
            fprintf(stderr, "--http %s: Illegal argument\n", sslhcfg_http->sval [cl_i]);
            exit(1);
        }
        
        int param_len, i, found = -1;
        struct sslhcfg_protocols_item* group;

        for (i = 0; i < cfg->protocols_len; i++) {
            if (!strncmp(cfg->protocols [i].name, "http",
                         4)) {
                found = i;
                break;
            }
        }
        if (found == -1) {
            cfg->protocols_len++;
            cfg->protocols = realloc(cfg->protocols, cfg->protocols_len * sizeof(*cfg->protocols));
            group = & cfg->protocols [cfg->protocols_len - 1];
        } else {
            group = & cfg->protocols [found];
        }


        sslhcfg_protocols_init(group);
        param_len = 4;
        group->name = calloc(1, param_len + 1);
        memcpy(group->name, "http", param_len);
        param_len = pmatch[1].rm_eo - pmatch[1].rm_so;
        group->host = calloc(1, param_len + 1);
        memcpy(group->host, sslhcfg_http->sval [cl_i]+pmatch[1].rm_so, param_len);
        param_len = pmatch[2].rm_eo - pmatch[2].rm_so;
        group->port = calloc(1, param_len + 1);
        memcpy(group->port, sslhcfg_http->sval [cl_i]+pmatch[2].rm_so, param_len);
    }
#define MAX_MATCH 10
    for (cl_i = 0; cl_i < sslhcfg_adb->count; cl_i++) {
        regex_t preg;
        regmatch_t pmatch[MAX_MATCH];
        int res = regcomp(&preg, "(\\w+):(\\w+)", REG_EXTENDED);
        if (res) {
            int errlen = regerror(res, &preg, NULL, 0);
            char* errmsg = malloc(errlen);
            regerror(res, &preg, errmsg, errlen);

            fprintf(stderr, "(\\w+):(\\w+): %s\n", errmsg);
            exit(1);
        }
        res = regexec(&preg, sslhcfg_adb->sval [cl_i], MAX_MATCH, &pmatch[0], 0);
        if (res) {
            fprintf(stderr, "--adb %s: Illegal argument\n", sslhcfg_adb->sval [cl_i]);
            exit(1);
        }
        
        int param_len, i, found = -1;
        struct sslhcfg_protocols_item* group;

        for (i = 0; i < cfg->protocols_len; i++) {
            if (!strncmp(cfg->protocols [i].name, "adb",
                         3)) {
                found = i;
                break;
            }
        }
        if (found == -1) {
            cfg->protocols_len++;
            cfg->protocols = realloc(cfg->protocols, cfg->protocols_len * sizeof(*cfg->protocols));
            group = & cfg->protocols [cfg->protocols_len - 1];
        } else {
            group = & cfg->protocols [found];
        }


        sslhcfg_protocols_init(group);
        param_len = 3;
        group->name = calloc(1, param_len + 1);
        memcpy(group->name, "adb", param_len);
        param_len = pmatch[1].rm_eo - pmatch[1].rm_so;
        group->host = calloc(1, param_len + 1);
        memcpy(group->host, sslhcfg_adb->sval [cl_i]+pmatch[1].rm_so, param_len);
        param_len = pmatch[2].rm_eo - pmatch[2].rm_so;
        group->port = calloc(1, param_len + 1);
        memcpy(group->port, sslhcfg_adb->sval [cl_i]+pmatch[2].rm_so, param_len);
    }
#define MAX_MATCH 10
    for (cl_i = 0; cl_i < sslhcfg_socks5->count; cl_i++) {
        regex_t preg;
        regmatch_t pmatch[MAX_MATCH];
        int res = regcomp(&preg, "(\\w+):(\\w+)", REG_EXTENDED);
        if (res) {
            int errlen = regerror(res, &preg, NULL, 0);
            char* errmsg = malloc(errlen);
            regerror(res, &preg, errmsg, errlen);

            fprintf(stderr, "(\\w+):(\\w+): %s\n", errmsg);
            exit(1);
        }
        res = regexec(&preg, sslhcfg_socks5->sval [cl_i], MAX_MATCH, &pmatch[0], 0);
        if (res) {
            fprintf(stderr, "--socks5 %s: Illegal argument\n", sslhcfg_socks5->sval [cl_i]);
            exit(1);
        }
        
        int param_len, i, found = -1;
        struct sslhcfg_protocols_item* group;

        for (i = 0; i < cfg->protocols_len; i++) {
            if (!strncmp(cfg->protocols [i].name, "socks5",
                         6)) {
                found = i;
                break;
            }
        }
        if (found == -1) {
            cfg->protocols_len++;
            cfg->protocols = realloc(cfg->protocols, cfg->protocols_len * sizeof(*cfg->protocols));
            group = & cfg->protocols [cfg->protocols_len - 1];
        } else {
            group = & cfg->protocols [found];
        }


        sslhcfg_protocols_init(group);
        param_len = 6;
        group->name = calloc(1, param_len + 1);
        memcpy(group->name, "socks5", param_len);
        param_len = pmatch[1].rm_eo - pmatch[1].rm_so;
        group->host = calloc(1, param_len + 1);
        memcpy(group->host, sslhcfg_socks5->sval [cl_i]+pmatch[1].rm_so, param_len);
        param_len = pmatch[2].rm_eo - pmatch[2].rm_so;
        group->port = calloc(1, param_len + 1);
        memcpy(group->port, sslhcfg_socks5->sval [cl_i]+pmatch[2].rm_so, param_len);
    }


    return 1;
}
