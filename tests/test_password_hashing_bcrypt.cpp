//
// Created by Ivan Shynkarenka on 05.06.2019
//

#include "test.h"

#include "security/password_hashing_bcrypt.h"

using namespace CppSecurity;

TEST_CASE("'bcrypt' password hashing", "[CppSecurity]")
{
    BcryptPasswordHashing bcrypt;

    // Generate digest
    std::string digest = bcrypt.GenerateEncodedDigest("passw0rd");
    REQUIRE(digest.size() > 0);

    // Validate digest
    REQUIRE(!bcrypt.ValidateEncodedDigest("password", digest));
    REQUIRE(bcrypt.ValidateEncodedDigest("passw0rd", digest));
}
