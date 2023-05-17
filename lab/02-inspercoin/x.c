void broadcast_transaction(char *date_transaction,
                           unsigned char *address_from,
                           unsigned char *address_to,
                           char *amount,
                           char *reward,
                           unsigned char *signature,
                           char *base)
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        char *args = malloc(COIN_ARGS_SIZE * sizeof(char));

        printf("\n\nSS: [%s]\n\n", signature);
        sprintf(args, "%sbroadcast/transaction?date_transaction=%s&address_from=%s&address_to=%s&amount=%s&reward=%s&signature=%s",
                base,
                date_transaction,
                address_from,
                address_to,
                amount,
                reward,
                signature);

        printf("\n\nURL : [%s]\n\n", args);
        curl_easy_setopt(curl, CURLOPT_URL, args);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");

        // Perform the request and capture the response
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            free(args);
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        // Clean up
        curl_easy_cleanup(curl);

        free(args);
    }
}
