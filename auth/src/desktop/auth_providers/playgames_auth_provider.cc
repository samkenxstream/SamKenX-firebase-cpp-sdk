/*
 * Copyright 2017 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "app/src/assert.h"
#include "auth/src/desktop/auth_providers/playgames_auth_credential.h"
#include "auth/src/desktop/credential_impl.h"
#include "auth/src/include/firebase/auth/credential.h"

namespace firebase {
namespace auth {

// static
Credential PlayGamesAuthProvider::GetCredential(
    const char* const server_auth_code) {
  FIREBASE_ASSERT_RETURN(Credential(), server_auth_code);
  return Credential{
      new CredentialImpl{new PlayGamesAuthCredential(server_auth_code)}};
}

// static
const char* PlayGamesAuthProvider::GetProviderId() {
  return "playgames.google.com";
}

}  // namespace auth
}  // namespace firebase
