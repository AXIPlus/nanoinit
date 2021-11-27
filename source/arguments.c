#include "arguments.h"
#include <argp.h>
#include <string.h>
#include <stdlib.h>

static nanoinit_arguments_t arguments = {0};

const char *argp_program_version = "nanoinit v0.0.1 build 123451234";   //checkAL
const char *argp_program_bug_address = "<adrian@axiplus.com>";
static char doc[] = "nanoinit - descriere aici";    //checkAL

static struct argp_option options[] = {
    { "config-file", 'c', "/path/to/config.json", 0, "Specifies the configuration JSON file. Default value is null, which means that no apps will be run, but nanoinit will sleep for infinity and wait for a kill signal.", 0 },
    { "config-json-object", 'j', "nanoinit-settings", 0, "Specifies the parent JSON object. Default value is null, which means that it will look directly into the root of the JSON file.", 0},
    { "log-path", 'l', "/path/to/log.txt", 0, "Specified the path for writing log-files. Default only uses stderr and stdout for logging.", 0 },
    { "verbose", 'v', "0-2", 0, "Specified application print verbosity level. Values are 0(nanoinit ERR)-default, 1(application ERR), 2(LOG).", 0 },
    { 0 } 
};

static error_t argp_parse_cb(int key, char *arg, struct argp_state *state);

const nanoinit_arguments_t *arguments_init(int argc, char **argv) {
    //parse provided command line arguments
    struct argp argp = { options, argp_parse_cb, 0, doc, 0, 0, 0 };
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    return &arguments;
}

static error_t argp_parse_cb(int key, char *arg, struct argp_state *state) {
    nanoinit_arguments_t *iter_arguments = state->input;
    switch (key) {
        case 'c':
            if(arg == 0) {
                return ARGP_ERR_UNKNOWN;
            }

            iter_arguments->config_file = strdup(arg);
            if(iter_arguments->config_file == 0) {
                return ARGP_ERR_UNKNOWN;
            }
            break;

        case 'j':
            if(arg == 0) {
                return ARGP_ERR_UNKNOWN;
            }

            iter_arguments->config_json_object = strdup(arg);
            if(iter_arguments->config_json_object == 0) {
                return ARGP_ERR_UNKNOWN;
            }
            break;

        case 'l':
            if(arg == 0) {
                return ARGP_ERR_UNKNOWN;
            }

            iter_arguments->log_path = strdup(arg);
            if(iter_arguments->log_path == 0) {
                return ARGP_ERR_UNKNOWN;
            }
            break;

        case 'v':
            if(arg == 0) {
                return ARGP_ERR_UNKNOWN;
            }

            iter_arguments->verbosity_level  = arg[0] - '0';
            if((iter_arguments->verbosity_level < 0) || (iter_arguments->verbosity_level > 2)) {
                //invalid verbosity level
                argp_usage(state);
            }
            break;

        case ARGP_KEY_ARG:
            if (state->arg_num >= 2) {
                argp_usage(state);
            }
            break;

        case ARGP_KEY_END:

            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }
    
    return 0;
}

void arguments_free() {
    free(arguments.config_file);
    free(arguments.config_json_object);
    free(arguments.log_path);
}